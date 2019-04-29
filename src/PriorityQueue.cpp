#include <iostream>
#include <stdio>

#include "../include/PriorityQueue.hpp"


Node* extractMinimum(){
  if(length == 0){
    return NULL;
  }

  Node* min = priorityQueue[1];
  priorityQueue[1] = priorityQueue[length];
  --length;
  minHeapify(1);
  return min;
}


void minHeapify(int index){
  int leftChildIndex = 2*index;
  int rightChildIndex = 2*index+1;
  int smallestIndex = index;
  if(leftChildIndex<= length && isSmallerNodes(priorityQueue[leftChildIndex],
  priorityQueue[index])){
    smallestIndex = leftChildIndex;
  }
  if(rightChildIndex<= length && isSmallerNodes(priorityQueue[rightChildIndex],
  priorityQueue[smallestIndex])){
    smallestIndex = rightChildIndex;
  }
  if(smallestIndex != index){
    swap(priorityQueue[index],priorityQueue[smallestIndex]);
    minHeapify(smallestIndex);
  }
}

void swap(Node* fst, Node* snd){
  Node* buff= fst;
  priorityQueue[fstIndex] = priorityQueue[sndIndex];
  priorityQueue[sndIndex] = buff;
}

bool decreaseElementValue(Node priorityQueue[],int index, int toValue){
  Node newNode = new Node(toValue);
  if(isSmallerNodes(priorityQueue[index], newNode)){
    return false;
  }
  setValue(priorityQueue[index], toValue);
  int parentIndex = index/2;
  while(index>1 && isSmallerNodes(priorityQueue[index], priorityQueue[parentIndex])){
    swap(&priorityQueue[index], &priorityQueue[parentIndex]);
    index /=2;
    parentIndex = index/2;
  }
  return true;
}

bool insertElement(Node priorityQueue[], Node element){
  ++length;
  int elementValue = getValue(element);
  priorityQueue[length] = setValue(element,INT_MAX);
  return decreaseElementValue(priorityQueue[], length, elementValue);
}

void deleteElement(Node priorityQueue[], int index){
  swap(priorityQueue[index],priorityQueue[1]);
  extractMinimum(priorityQueue);
  return;
}

bool isEmpty(Node priorityQueue[]){
  if(priorityQueue[1]){
    return true;
  }
  return false;
}
