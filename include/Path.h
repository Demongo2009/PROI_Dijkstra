#ifndef PATH_H
#define PATH_H

#include "Graph.h"

template <class T>
class Path{
  std::vector<Node<T>*> nodes;
public:
  Path(Node<T>* nodePtr);
  void addNode(Node<T>* nodePtr);
  std::string toString();
};

#endif
