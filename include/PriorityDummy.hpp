#ifndef PRIORITY_DUMMY_HPP
#define PRIORITY_DUMMY_HPP
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
  ~PriorityQueue();
  void setPriority(uint newPriority);
  uint getPriority();
  T getElement();
};

#endif
