#ifndef EDGE_H
#define EDGE_H
#define MAX_DISTANCE 2147483647

#include "Node.h"

template <class T>
class Node;

template <class T>
class Edge{
	Node<T>* startNodePtr=nullptr; // start node pointer
	Node<T>* endNodePtr=nullptr; // end node pointer
	uint distance=MAX_DISTANCE; // distance set initially to max
public:
	Edge(Node<T>* startNode, Node<T>* endNode); //constructor without distance
	Edge(Node<T>* startNode, Node<T>* endNode, uint distance); // constructor with distance
	Node<T>* getStartNode(); // returns pointer on start node
	Node<T>* getEndNode(); // returns pointer on end node
	uint getDistance(); // returns distance
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
