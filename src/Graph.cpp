#include <iostream>
#include <stdio>

#define INC "../include
#include INCGraph.hpp"

template <T>
void Graph::addNode(T nodeContents){
  ++numOfNodes;
  uint index = nodeVector.size();
  Node<T> newNode = new Node<T>(&nodeContents,index);
  nodeVector.push_back(newNode);
}

bool Graph::addEdge(uint fstIndex, uint sndIndex, uint distance){
  Edge newEdge = new Edge(nodeVector[fstIndex], nodeVector[sndIndex], distance);
  nodeVector[fstIndex].addEdge(newEdge);
  nodeVector[sndIndex].addEdge(newEdge);
}
