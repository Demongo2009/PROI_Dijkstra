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
  Edge(Node<T> startNode, Node<T> endNode);
  Edge(Node<T>& startNode, Node<T>& endNode, uint distance);
  Node<T> getStartNode();
  Node<T> getEndNode();
  uint getDistance();
};

#endif
