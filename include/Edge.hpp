#ifndef NODE_HPP
#define NODE_HPP
#define MAX_DISTANCE 2147483647


class Edge{
  Node* startNodePtr=nullptr;
  Node* endNodePtr=nullptr;
  uint distance=MAX_DISTANCE;
public:
  Edge(Node startNode);
  Edge(Node startNode, Node endNode);
  Edge(Node startNode, Node endNode, uint distance);
  ~Edge();
  Node getStartNode();
  Node getEndNode();
  uint getDistance();
}

#endif
