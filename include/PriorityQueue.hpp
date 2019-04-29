#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP


class PriorityQueue{
  Node** priorityQueue;
public:
  Node extractMinimum(Node priorityQueue[]);
  bool decreaseElementValue(Node priorityQueue[], int index, int toValue);
  bool insertElement(Node priorityQueue[], Node element);
  void deleteElement(Node priorityQueue[], int index);
  bool isEmpty(Node priorityQueue[]);
  void minHeapify(int index);
  bool isSmallerNodes(Node fst, Node snd);
  void swap(int fstIndex, int sndIndex);
  void setValue(Node node,int value);
  int getValue(Node node);
};


#endif
