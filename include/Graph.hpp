#ifndef GRAPH_HPP
#define GRAPH_HPP

typedef unsigned int uint;

template <class T>
class Graph{
  std::vector<Node<T>> nodeVector;
  int numOfNodes=0;
public:
  void addNode<T>(T nodeContents);
  bool addEdge(uint fstIndex, uint sndIndex, uint distance);
};


#endif
