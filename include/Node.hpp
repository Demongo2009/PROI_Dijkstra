#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node{
  T nodeContents;
  uint index;
  std::vector<Edge> edges;
public:
  Node();
  ~Node();
  std::vector<Node> getAdjacentNodes();
  std::vector<Edge> getEdges();
  void addEdge();
  uint getIndex();
};

#endif
