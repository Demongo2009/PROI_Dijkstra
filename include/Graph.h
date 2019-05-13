#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

typedef unsigned int uint;


template <class T>
class Graph{
	std::vector<Node<T>*> nodeVector; // vector of pointers on nodes
	int numOfNodes=0; // number of nodes
public:
	void addNode(T* nodeContents); // adds node with contents
	bool addEdge(uint fstIndex, uint sndIndex, uint distance); // adds edge given indexes and distance
	std::vector<Node<T>*> getNodes(); //returns vector of pointers on nodes
};

template <typename T>
void Graph<T>::addNode(T* nodeContents){
	++numOfNodes;
	uint index = nodeVector.size();
//	Node<T> newNode = Node<T>(nodeContents,index);
	nodeVector.push_back(new Node<T>(nodeContents,index));
	return;
}

template <class T>
bool Graph<T>::addEdge(uint fstIndex, uint sndIndex, uint distance){
	Edge<T> newEdge = Edge<T>(nodeVector[fstIndex], nodeVector[sndIndex], distance);
	nodeVector[fstIndex]->addEdge(newEdge);
	nodeVector[sndIndex]->addEdge(newEdge);
	return true;
}

template <class T>
std::vector<Node<T>*> Graph<T>::getNodes(){
	return nodeVector;
}




#endif
