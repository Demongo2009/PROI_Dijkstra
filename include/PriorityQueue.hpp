#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP


typedef unsigned int uint;

template <class T>
class MinPriorityQueue{
  PriorityDummy<T>* priorityQueueArray;
  uint length=0;
  uint capacity=0;
public:
  MinPriorityQueue();
  ~MinPriorityQueue();
  PriorityDummy<T>* extractMinimum<T>();
  bool decreaseDummyPriority<T>(uint index, uint toPriority);
  bool insertDummy<T>(PriorityDummy<T> dummy);
  void deleteDummy(uint index);
  bool isEmpty();
  void minHeapify<T>(uint index);
  bool isSmallerPriority(uint fstIndex, uint sndIndex);
  void swap<T>(uint fstIndex, uint sndIndex);
  void setPriority(uint index,uint priority);
  uint getPriroity(uint index);
};


#endif
