#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

typedef unsigned int uint;


template <class T>
class Graph{
  std::vector<Node<T>> nodeVector;
  int numOfNodes=0;
public:
  void addNode(T nodeContents);
  bool addEdge(uint fstIndex, uint sndIndex, uint distance);
  std::vector<Node<T>> getNodes();
};


#endif
