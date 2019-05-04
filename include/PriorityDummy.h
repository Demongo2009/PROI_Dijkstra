#ifndef PRIORITY_DUMMY_H
#define PRIORITY_DUMMY_H
#define MAX_PRIORITY 2147483647
#define FIRST_IN_QUEUE 1

typedef unsigned int uint;

template <class T>
class PriorityDummy{
  uint priority=MAX_PRIORITY;
  T* elementPtr=nullptr;
public:
  PriorityDummy(T element);
  PriorityDummy(uint priority):priority(priority){};
  PriorityDummy(T element, uint priority);
  void setPriority(uint newPriority);
  uint getPriority();
  T getElement();
};

#endif
