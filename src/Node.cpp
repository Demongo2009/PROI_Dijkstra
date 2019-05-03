#include <iostream>
#include <stdio>

#include "../include/Node.hpp"

template <T>
Node::Node(T* nodeContents, uint index){
  nodeContents = nodeContents;
  index = index;
}

std::vector<Node> Node::getAdjacentNodes(){
  std::vector<Node> nodes;
  for(Edge edge: edges){
    nodes.push_back(*edge.getStartNode());
    nodes.push_back(*edge.getEndNode());
  }
  return nodes;
}

std::vector<Edge> Node::getEdges(){
  return edges;
}

void Node::addEdge(Edge edge){
  edges.push_back(edge);
}

uint Node::getIndex(){
  return index;
}
