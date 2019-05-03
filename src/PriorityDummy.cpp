#include <iostream>
#include <stdio>

#include "../include/PriorityDummy.hpp"

template <T>
PriorityDummy::PriorityDummy(T element){
  elementPtr=&element;
}


PriorityDummy::~PriorityDummy(){
}

void PriorityDummy::setPriority(uint newPriority){
  priority= newPriority;
}

uint PriorityDummy::getPriority(){
  return priority;
}

template <T>
T PriorityDummy::getElement(){
  return *elementPtr;
}
