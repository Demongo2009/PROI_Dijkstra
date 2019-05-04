#include <iostream>
#include <typeinfo>


#include "../include/PriorityDummy.h"

template <class T>
PriorityDummy<T>::PriorityDummy(T element){
  elementPtr=&element;
}
template
PriorityDummy<int>::PriorityDummy(int element);

template <class T>
PriorityDummy<T>::PriorityDummy(T element, uint priorityInput){
  priority = priorityInput;
  elementPtr=&element;
}
template
PriorityDummy<int>::PriorityDummy(int element, uint priority);

template <class T>
void PriorityDummy<T>::setPriority(uint newPriority){
  priority= newPriority;
}
template
void PriorityDummy<int>::setPriority(uint newPriority);

template <class T>
uint PriorityDummy<T>::getPriority(){
  return priority;
}
template
uint PriorityDummy<int>::getPriority();

template <class T>
T PriorityDummy<T>::getElement(){
  return *elementPtr;
}
template
int PriorityDummy<int>::getElement();
