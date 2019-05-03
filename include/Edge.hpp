#ifndef NODE_HPP
#define NODE_HPP


class Edge{
  Node startNode;
  Node endNode;
  uint distance;
public:
  Node getStartNode();
  Node getEndNode();
  uint getDistance();
}

#endif
