#include <iostream>
#include <typeinfo>


#include "../include/MinPriorityQueue.h"
#include <vector>

template <class T>
MinPriorityQueue<T>::MinPriorityQueue(){
  dummyArray = (PriorityDummy<int>*)malloc(sizeof(PriorityDummy<int>));
}

template
MinPriorityQueue<int>::MinPriorityQueue();

template <class T>
MinPriorityQueue<T>::~MinPriorityQueue(){
  delete[] dummyArray;
}

template
MinPriorityQueue<int>::~MinPriorityQueue();

// gives minimum which is top of queue element,
template <class T>
PriorityDummy<T>* MinPriorityQueue<T>::extractMinimum(){
  if(length == 0){
    return nullptr;
  }

  PriorityDummy<T>* min = &dummyArray[FIRST_IN_QUEUE];
  dummyArray[FIRST_IN_QUEUE] = dummyArray[length];
  --length;
  minHeapify(FIRST_IN_QUEUE);
  return min;
}

template
PriorityDummy<int>* MinPriorityQueue<int>::extractMinimum();

// porownoje synow z ojcem jezeli dziecko jest mniejsze to zamienia je z ojcem
// i wykonuje algorytm jeszcze raz
template <class T>
void MinPriorityQueue<T>::minHeapify(uint index){
  uint leftChildIndex = 2*index;
  uint rightChildIndex = 2*index+1;
  uint smallestIndex = index;
  if(leftChildIndex<= length && isSmallerPriority(leftChildIndex,index)){
    smallestIndex = leftChildIndex;
  }
  if(rightChildIndex<= length && isSmallerPriority(rightChildIndex,smallestIndex)){
    smallestIndex = rightChildIndex;
  }
  if(smallestIndex != index){
    swap(index,smallestIndex);
    minHeapify(smallestIndex);
  }
}
template
void MinPriorityQueue<int>::minHeapify(uint index);


template <class T>
void MinPriorityQueue<T>::swap(uint fstIndex, uint sndIndex){
  PriorityDummy<T> buff= dummyArray[fstIndex];
  dummyArray[fstIndex] = dummyArray[sndIndex];
  dummyArray[sndIndex] = buff;
}
template
void MinPriorityQueue<int>::swap(uint fstIndex, uint sndIndex);

// ustawia priorytet pod indeksem index po czym sprawdza czy jest on
// mniejszy od ojca, jesli tak to zamienia miejscami, tak dlugo az
// struktura heap zostanie przywrocona
template <class T>
void MinPriorityQueue<T>::decreaseDummyPriority(uint index, uint toValue){
  setPriority(index, toValue);
  uint parentIndex = index/2;
  while(index>FIRST_IN_QUEUE && isSmallerPriority(index, parentIndex)){
    swap(index, parentIndex);
    index /=2;
    parentIndex = index/2;
  }
}
template
void MinPriorityQueue<int>::decreaseDummyPriority(uint index, uint toValue);

// uzywajac decreaseDummyPriority wstawia dummy do struktury
// wstawia go na koniec zmienia jego priorytet na maxymalny,
// po czym zmienia go poprzez decreaseDummyPriority dzieki czemu
// struktura jest zachowana
template <class T>
void MinPriorityQueue<T>::insertDummy(PriorityDummy<Node<T>> dummy){
  ++length;
  if(length>capacity){
    ++capacity;
    dummyArray = (PriorityDummy<T>*)realloc(dummyArray, capacity*sizeof(PriorityDummy<T>));
  }
  uint dummyPriority = dummy.getPriority();
  dummyArray[length] = dummy;
  setPriority(length,MAX_PRIORITY);
  decreaseDummyPriority(length, dummyPriority);
}
template
void MinPriorityQueue<int>::insertDummy(PriorityDummy<int> dummy);

template <class T>
bool MinPriorityQueue<T>::isSmallerPriority(uint fstIndex, uint sndIndex){
  return dummyArray[fstIndex].getPriority() < dummyArray[sndIndex].getPriority();
}
template
bool MinPriorityQueue<int>::isSmallerPriority(uint fstIndex, uint sndIndex);

template <class T>
void MinPriorityQueue<T>::setPriority(uint index, uint priority){
  dummyArray[index].setPriority(priority);
}
template
void MinPriorityQueue<int>::setPriority(uint index, uint priority);

template <class T>
uint MinPriorityQueue<T>::getPriority(uint index){
  return dummyArray[index].getPriority();
}
template
uint MinPriorityQueue<int>::getPriority(uint index);

template <class T>
uint MinPriorityQueue<T>::searchForElement(uint nodeIndex){
  for(uint i=1;i<=length;++i){
    if (dummyArray[i].getElement().getIndex() == nodeIndex){
      return i;
    }
  }
  return 0;
}
template
uint MinPriorityQueue<int>::searchForElement(uint nodeIndex);

template <class T>
void MinPriorityQueue<T>::deleteDummy(uint index){
  swap(index,FIRST_IN_QUEUE);
  extractMinimum();
  return;
}
template
void MinPriorityQueue<int>::deleteDummy(uint index);


template <class T>
bool MinPriorityQueue<T>::isEmpty(){
  if(length==0){
    return true;
  }
  return false;
}

template
bool MinPriorityQueue<int>::isEmpty();
