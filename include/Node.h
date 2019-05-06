#ifndef NODE_H
#define NODE_H

#include "Edge.h"
#include <vector>

typedef unsigned int uint;

template <class T>
class Edge;

template <class T>
class Node{
	T* nodeContents;
	uint index;
	std::vector<Edge<T>> edges;
	bool visited=false;
	bool inQueue=false;
	Node* parentNode=nullptr;
public:
	Node(T* nodeContents, uint index);
//	std::vector<Node> getAdjacentNodes();
	std::vector<Edge<T>> getEdges();
	void addEdge(Edge<T> edge);
	uint getIndex();
	void setContents(T* contents);
	T* getContents();
	bool isVisited();
	void setVisited(bool b);
	void setInQueue(bool b);
	bool isInQueue();
	void setParentNode(Node* parentNode);
	Node* getParentNode();
};

template <class T>
Node<T>::Node(T* nodeContentsInput, uint indexInput){
	nodeContents = nodeContentsInput;
	index = indexInput;
}

template <class T>
std::vector<Edge<T>> Node<T>::getEdges(){
	return edges;
}

template <class T>
void Node<T>::addEdge(Edge<T> edge){
	edges.push_back(edge);
}

template <class T>
uint Node<T>::getIndex(){
	return index;
}

template <class T>
void Node<T>::setContents(T* contents){
	nodeContents = contents;
}

template <class T>
T* Node<T>::getContents(){
	return nodeContents;
}

template <class T>
bool Node<T>::isVisited(){
	return visited;
}

template <class T>
bool Node<T>::isInQueue(){
	return inQueue;
}

template <class T>
void Node<T>::setVisited(bool b){
	visited = b;
}

template <class T>
void Node<T>::setInQueue(bool b){
	inQueue = b;
}

template <class T>
void Node<T>::setParentNode(Node* parentNodeInput){
	parentNode = parentNodeInput;
}


template <class T>
Node<T>* Node<T>::getParentNode(){
	return parentNode;
}

#endif