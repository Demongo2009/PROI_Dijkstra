#ifndef NODE_H
#define NODE_H

#include "Edge.h"
#include <vector>

typedef unsigned int uint;

template <class T>
class Edge;

template <class T>
class Node{
	T* nodeContents; // contents of node
	uint index; // index of node
	std::vector<Edge<T>> edges; // vector of edges
	bool visited=false; // is visited
	bool inQueue=false; // is in queue
	Node* parentNode=nullptr; // pointer to parent node
public:
	Node(T* nodeContents, uint index); // constructor
//	std::vector<Node> getAdjacentNodes();
	std::vector<Edge<T>> getEdges(); // returns vector of edges
	void addEdge(Edge<T> edge); // adds edge
	uint getIndex(); // returns index
	void setContents(T* contents); // sets contents
	T* getContents(); // returns contents
	bool isVisited(); // checks if node is visited
	void setVisited(bool b); // sets visited
	void setInQueue(bool b); // sets inQueue
	bool isInQueue(); //checks if node is in queue
	void setParentNode(Node* parentNode); // sets parent node of node
	Node* getParentNode(); // returns parent node
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
