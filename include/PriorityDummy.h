#ifndef PRIORITY_DUMMY_H
#define PRIORITY_DUMMY_H
#define MAX_PRIORITY 2147483647
#define FIRST_IN_QUEUE 1

typedef unsigned int uint;
#include "Graph.h"

template <class T>
class PriorityDummy{
	uint priority=MAX_PRIORITY; // priority initially set to max
	Node<T>* nodePtr=nullptr; // pointer on node
public:
	PriorityDummy(T element); // constructor
	PriorityDummy(uint priority):priority(priority){}; // constructor
	PriorityDummy(Node<T>* nodePtr):nodePtr(nodePtr){}; // constructor
	PriorityDummy(T element, uint priority); // constructor
	PriorityDummy(Node<T>* node, uint priority); // constructor
	~PriorityDummy(); // destructor
	void setPriority(uint newPriority); // sets priority
	uint getPriority(); // returns priority
	Node<T>* getNode(); // returns pointed to node
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
