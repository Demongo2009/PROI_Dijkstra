#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PriorityDummy.h"
#include "Graph.h"
#include <vector>


typedef unsigned int uint;

template <class T>
class MinPriorityQueue{
	std::vector<PriorityDummy<T>*> dummyArray;
	uint length=0;
public:
	MinPriorityQueue();
	~MinPriorityQueue();
	PriorityDummy<T>* extractMinimum();
	void decreaseDummyPriority(uint index, uint toPriority);
	void insertDummy(PriorityDummy<T>* dummy);
	void insertNode(Node<T>* node,uint priority);
	void deleteDummy(uint index);
	bool isEmpty();
	void minHeapify(uint index);
	bool isSmallerPriority(uint fstIndex, uint sndIndex);
	void swap(uint fstIndex, uint sndIndex);
	void setPriority(uint index,uint priority);
	uint getPriority(uint index);
	PriorityDummy<T>* searchForDummy(Node<T>* node);
	uint getDummyIndex(PriorityDummy<T> dummy);
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



// gives minimum which is top of queue element,
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



// porownoje synow z ojcem jezeli dziecko jest mniejsze to zamienia je z ojcem
// i wykonuje algorytm jeszcze raz
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


// ustawia priorytet pod indeksem index po czym sprawdza czy jest on
// mniejszy od ojca, jesli tak to zamienia miejscami, tak dlugo az
// struktura heap zostanie przywrocona
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


// uzywajac decreaseDummyPriority wstawia dummy do struktury
// wstawia go na koniec zmienia jego priorytet na maxymalny,
// po czym zmienia go poprzez decreaseDummyPriority dzieki czemu
// struktura jest zachowana
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