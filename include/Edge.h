#ifndef EDGE_H
#define EDGE_H
#define MAX_DISTANCE 2147483647

#include "Node.h"

template <class T>
class Node;

template <class T>
class Edge{
	Node<T>* startNodePtr=nullptr;
	Node<T>* endNodePtr=nullptr;
	uint distance=MAX_DISTANCE;
public:
	Edge(Node<T>* startNode, Node<T>* endNode);
	Edge(Node<T>* startNode, Node<T>* endNode, uint distance);
	Node<T>* getStartNode();
	Node<T>* getEndNode();
	uint getDistance();
};

template <class T>
Edge<T>::Edge(Node<T>* startNode, Node<T>* endNode){
	startNodePtr = startNode;
	endNodePtr = endNode;
}


template <class T>
Edge<T>::Edge(Node<T>* startNode, Node<T>* endNode, uint distanceInput){
	startNodePtr = startNode;
	endNodePtr = endNode;
	distance = distanceInput;
}


template <class T>
Node<T>* Edge<T>::getStartNode(){
	return startNodePtr;
}


template <class T>
Node<T>* Edge<T>::getEndNode(){
	return endNodePtr;
}


template <class T>
uint Edge<T>::getDistance(){
	return distance;
}




#endif