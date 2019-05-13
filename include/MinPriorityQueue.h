#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PriorityDummy.h"
#include "Graph.h"
#include <vector>


typedef unsigned int uint;

template <class T>
class MinPriorityQueue{
	std::vector<PriorityDummy<T>*> dummyArray; // vector of pointers on dummys
	uint length=0; // length of array
public:
	MinPriorityQueue(); // constructor
	~MinPriorityQueue(); // destructor
	PriorityDummy<T>* extractMinimum(); // returns minimum and preserves heap structure
	void decreaseDummyPriority(uint index, uint toPriority); // decreases dummy priority and preserves heap structure
	void insertDummy(PriorityDummy<T>* dummy); // insterts dummy and preserves heap structure
	void insertNode(Node<T>* node,uint priority); // inserts dummy and preserves heap structure
	void deleteDummy(uint index); // deletes dummy
	bool isEmpty(); //checks if array is empty
	void minHeapify(uint index); // returns heap structure from index
	bool isSmallerPriority(uint fstIndex, uint sndIndex); // checks fst has smaller priority than snd
	void swap(uint fstIndex, uint sndIndex); // swaps dummys under indexes
	void setPriority(uint index,uint priority); // sets priority of index
	uint getPriority(uint index); // returns priority of index
	PriorityDummy<T>* searchForDummy(Node<T>* node); // searches for dummy with node
	uint getDummyIndex(PriorityDummy<T> dummy); // returns dummy index
};

template <class T>
MinPriorityQueue<T>::MinPriorityQueue(){
	dummyArray.push_back(new PriorityDummy<T>(nullptr));
}


template <class T>
MinPriorityQueue<T>::~MinPriorityQueue(){
//	for(PriorityDummy<T>* ptr: dummyArray){
//		delete ptr;
//	}
}



// gives minimum which is top of queue element
template <class T>
PriorityDummy<T>* MinPriorityQueue<T>::extractMinimum(){
	if(length == 0){
		return nullptr;
	}

	PriorityDummy<T>* min = dummyArray[FIRST_IN_QUEUE];
	min->getNode()->setInQueue(false);
	dummyArray[FIRST_IN_QUEUE] = dummyArray[length];
	--length;
	minHeapify(FIRST_IN_QUEUE);
	return min;
}




// compares children with parent, if child is smaller then swaps it with parent and does algorithm once again
template <class T>
void MinPriorityQueue<T>::minHeapify(uint index){
	uint leftChildIndex = 2*index;
	uint rightChildIndex = 2*index+1;
	uint smallestIndex = index;
	if(leftChildIndex<= length && isSmallerPriority(leftChildIndex,index)){
		smallestIndex = leftChildIndex;
	}
	if(rightChildIndex<= length && isSmallerPriority(rightChildIndex,smallestIndex)){
		smallestIndex = rightChildIndex;
	}
	if(smallestIndex != index){
		swap(index,smallestIndex);
		minHeapify(smallestIndex);
	}
}



template <class T>
void MinPriorityQueue<T>::swap(uint fstIndex, uint sndIndex){
	PriorityDummy<T>* buff= dummyArray[fstIndex];
	dummyArray[fstIndex] = dummyArray[sndIndex];
	dummyArray[sndIndex] = buff;
}



// sets priority of index then checks if it is smaller then parrent if yes than changes places, until smaller heap is restored
template <class T>
void MinPriorityQueue<T>::decreaseDummyPriority(uint index, uint toValue){
	setPriority(index, toValue);
	uint parentIndex = index/2;
	while(index>FIRST_IN_QUEUE && isSmallerPriority(index, parentIndex)){
		swap(index, parentIndex);
		index /=2;
		parentIndex = index/2;
	}
}




// using decreaseDummy Priority inserts dummy into structure in the end and sets its priority to max then changes it so structure is preserved
template <class T>
void MinPriorityQueue<T>::insertDummy(PriorityDummy<T>* dummy){
	++length;
	uint dummyPriority = dummy->getPriority();
	dummy->setPriority(MAX_PRIORITY);
	dummyArray.push_back(dummy);
	dummyArray[length]=dummy;
	decreaseDummyPriority(length, dummyPriority);
}


template <class T>
void MinPriorityQueue<T>::insertNode(Node<T>* node,uint priority){
	node->setInQueue(true);
	insertDummy(new PriorityDummy<T>(node,priority));
}


template <class T>
bool MinPriorityQueue<T>::isSmallerPriority(uint fstIndex, uint sndIndex){
	return dummyArray[fstIndex]->getPriority() < dummyArray[sndIndex]->getPriority();
}


template <class T>
void MinPriorityQueue<T>::setPriority(uint index, uint priority){
	dummyArray[index]->setPriority(priority);
}


template <class T>
uint MinPriorityQueue<T>::getPriority(uint index){
	return dummyArray[index]->getPriority();
}


template <class T>
PriorityDummy<T>* MinPriorityQueue<T>::searchForDummy(Node<T>* node){
	uint nodeIndex = node->getIndex();
	for(uint i=1;i<=length;++i){
		if (dummyArray[i]->getNode()->getIndex() == nodeIndex){
			return dummyArray[i];
		}
	}
	return nullptr;
}


template <class T>
uint MinPriorityQueue<T>::getDummyIndex(PriorityDummy<T> dummy){
	Node<T>* node = dummy.getNode();
	for(uint i=1;i<=length;++i){
		if (dummyArray[i]->getNode()->getIndex() == node->getIndex()){
			return i;
		}
	}
	return 0;
}


template <class T>
void MinPriorityQueue<T>::deleteDummy(uint index){
	swap(index,FIRST_IN_QUEUE);
	extractMinimum();
	return;
}



template <class T>
bool MinPriorityQueue<T>::isEmpty(){
	if(length==0){
		return true;
	}
	return false;
}


#endif
