#include <iostream>
#include <typeinfo>

#include "../include/Graph.h"
#include <vector>

template <typename T>
void Graph<T>::addNode(T nodeContents){
  ++numOfNodes;
  uint index = nodeVector.size();
  Node<T> newNode = Node<T>(nodeContents,index);
  nodeVector.push_back(newNode);
}

template <class T>
bool Graph<T>::addEdge(uint fstIndex, uint sndIndex, uint distance){
  Edge<T> newEdge = Edge<T>(nodeVector[fstIndex], nodeVector[sndIndex], distance);
  nodeVector[fstIndex].addEdge(newEdge);
  nodeVector[sndIndex].addEdge(newEdge);
  return true;
}

template <class T>
std::vector<Node<T>> Graph<T>::getNodes(){
	return nodeVector;
}


template
void Graph<int>::addNode(int nodeContents);

template
bool Graph<int>::addEdge(uint fstIndex, uint sndIndex, uint distance);

template
std::vector<Node<int>> Graph<int>::getNodes();
