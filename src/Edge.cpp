#include <iostream>
#include <stdio>

#include "../include/Edge.hpp"


Edge::Edge(Node startNode){
  startNodePtr = &startNode;
}

Edge::Edge(Node startNode, Node endNode){
  startNodePtr = &startNode;
  endNodePtr = &endNode;
}

Edge::Edge(Node& startNode, Node& endNode, uint distance){
  startNodePtr = startNode;
  endNodePtr = endNode;
  distance = distance;
}

Edge::~Edge(){
}

Node Edge::getStartNode(){
  return *startNodePtr;
}

Node Edge::getEndNode(){
  return *endNodePtr;
}

uint Edge::getDistance(){
  return distance;
}
