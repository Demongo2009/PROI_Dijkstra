#include <iostream>
#include <stdio>

#include "../include/PriorityQueue.hpp"

MinPriorityQueue::MinPriorityQueue(){
  priorityQueueArray = malloc(1);
}

MinPriorityQueue::~MinPriorityQueue(){
  delete[] priorityQueueArray;
}

// gives minimum which is top of queue element,
template <T>
PriorityDummy<T>* MinPriorityQueue::extractMinimum(){
  if(length == 0){
    return nullptr;
  }

  PriorityDummy<T>* min = &priorityQueueArray[FIRST_IN_QUEUE];
  priorityQueueArray[FIRST_IN_QUEUE] = priorityQueueArray[length];
  --length;
  minHeapify<T>(FIRST_IN_QUEUE);
  return min;
}

// porownoje synow z ojcem jezeli dziecko jest mniejsze to zamienia je z ojcem
// i wykonuje algorytm jeszcze raz
template <T>
void MinPriorityQueue::minHeapify(uint index){
  uint leftChildIndex = 2*index;
  uint rightChildIndex = 2*index+1;
  uint smallestIndex = index;
  if(leftChildIndex<= length && isSmallerPriority<T>(leftChildIndex,index)){
    smallestIndex = leftChildIndex;
  }
  if(rightChildIndex<= length && isSmallerPriority<T>(rightChildIndex,smallestIndex)){
    smallestIndex = rightChildIndex;
  }
  if(smallestIndex != index){
    swap<T>(index,smallestIndex);
    minHeapify<T>(smallestIndex);
  }
}

template <T>
void MinPriorityQueue::swap(uint fstIndex, uint sndIndex){
  PriorityDummy<T> buff= priorityQueueArray[fstIndex];
  priorityQueueArray[fstIndex] = priorityQueueArray[sndIndex];
  priorityQueueArray[sndIndex] = buff;
}

// ustawia priorytet pod indeksem index po czym sprawdza czy jest on
// mniejszy od ojca, jesli tak to zamienia miejscami, tak dlugo az
// struktura heap zostanie przywrocona
template <T>
bool MinPriorityQueue::decreaseDummyPriority(uint index, uint toValue){
  PriorityDummy<T> newDummy = new PriorityDummy<T>(toValue);
  if(isSmallerPriority<T>(index, newDummy)){
    return false;
  }
  delete newDummy;
  setPriority<T>(index, toValue);
  uint parentIndex = index/2;
  while(index>FIRST_IN_QUEUE && isSmallerPriority<T>(index, parentIndex)){
    swap<T>(index, parentIndex);
    index /=2;
    parentIndex = index/2;
  }
  return true;
}

// uzywajac decreaseDummyPriority wstawia dummy do struktury
// wstawia go na koniec zmienia jego priorytet na maxymalny,
// po czym zmienia go poprzez decreaseDummyPriority dzieki czemu
// struktura jest zachowana
template <T>
bool MinPriorityQueue::insertDummy(PriorityDummy<T> dummy){
  ++length;
  if(length>capacity){
    ++capacity;
    priorityQueueArray = realloc(priorityQueueArray, capacity*sizeof(PriorityDummy<T>));
  }
  uint dummyPriority = getPriroity<T>(dummy);
  priorityQueueArray[length] = dummy;
  setPriority<T>(length,MAX_PRIORITY);
  return decreaseDummyPriority<T>(length, dummyPriority);
}


bool MinPriorityQueue::isSmallerPriority(uint fstIndex, uint sndIndex){
  return priorityQueueArray[fstIndex].getPriority() < priorityQueueArray[sndIndex].getPriority();
}


void MinPriorityQueue::setPriority(uint index, uint priority){
  priorityQueueArray[index].setPriority(priority);
}

uint MinPriorityQueue::getPriority(uint index){
  return priorityQueueArray[index].getPriority();
}



void MinPriorityQueue::deleteDummy(uint index){
  swap(index,FIRST_IN_QUEUE);
  extractMinimum();
  return;
}



bool MinPriorityQueue::isEmpty(){
  if(length==0){
    return true;
  }
  return false;
}
