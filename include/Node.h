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
  Node(T nodeContents, uint index);
  std::vector<Node> getAdjacentNodes();
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

#endif
