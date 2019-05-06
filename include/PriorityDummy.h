#ifndef PRIORITY_DUMMY_H
#define PRIORITY_DUMMY_H
#define MAX_PRIORITY 2147483647
#define FIRST_IN_QUEUE 1

typedef unsigned int uint;
#include "Graph.h"

template <class T>
class PriorityDummy{
	uint priority=MAX_PRIORITY;
	Node<T>* nodePtr=nullptr;
public:
	PriorityDummy(T element);
	PriorityDummy(uint priority):priority(priority){};
	PriorityDummy(Node<T>* nodePtr):nodePtr(nodePtr){};
	PriorityDummy(T element, uint priority);
	PriorityDummy(Node<T>* node, uint priority);
	~PriorityDummy();
	void setPriority(uint newPriority);
	uint getPriority();
	Node<T>* getNode();
};

template <class T>
PriorityDummy<T>::PriorityDummy(T element){
	nodePtr= new Node<T>(element);
}
template <class T>
PriorityDummy<T>::~PriorityDummy(){

}
template <class T>
PriorityDummy<T>::PriorityDummy(T element, uint priorityInput){
	priority = priorityInput;
	nodePtr= new Node<T>(element);
}
template <class T>
PriorityDummy<T>::PriorityDummy(Node<T>* node, uint priorityInput){
	priority = priorityInput;
	nodePtr= node;
}

template <class T>
void PriorityDummy<T>::setPriority(uint newPriority){
	priority= newPriority;
}


template <class T>
uint PriorityDummy<T>::getPriority(){
	return priority;
}

template <class T>
Node<T>* PriorityDummy<T>::getNode(){
	return nodePtr;
}

#endif