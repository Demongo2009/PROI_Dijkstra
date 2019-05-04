#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PriorityDummy.h"


typedef unsigned int uint;

template <class T>
class MinPriorityQueue{
  PriorityDummy<T>* dummyArray;
  uint length=0;
  uint capacity=0;
public:
  MinPriorityQueue();
  ~MinPriorityQueue();
  PriorityDummy<T>* extractMinimum();
  void decreaseDummyPriority(uint index, uint toPriority);
  void insertDummy(PriorityDummy<T> dummy);
  void deleteDummy(uint index);
  bool isEmpty();
  void minHeapify(uint index);
  bool isSmallerPriority(uint fstIndex, uint sndIndex);
  void swap(uint fstIndex, uint sndIndex);
  void setPriority(uint index,uint priority);
  uint getPriority(uint index);
  uint searchForElement(uint nodeIndex);
};


#endif
