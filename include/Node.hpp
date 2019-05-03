#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node{
  T* nodeContents;
  uint index;
  std::vector<Edge> edges;
  bool visited=false;
public:
  Node(T* nodeContents, uint index);
  ~Node();
  std::vector<Node> getAdjacentNodes();
  std::vector<Edge> getEdges();
  void addEdge(Edge edge);
  uint getIndex();
};

#endif
