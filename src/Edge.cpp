#include <iostream>
#include <typeinfo>


#include "../include/Edge.h"


template <class T>
Edge<T>::Edge(Node<T> startNode, Node<T> endNode){
  startNodePtr = &startNode;
  endNodePtr = &endNode;
}
template
Edge<int>::Edge(Node<int> startNode, Node<int> endNode);

template <class T>
Edge<T>::Edge(Node<T>& startNode, Node<T>& endNode, uint distanceInput){
  startNodePtr = startNode;
  endNodePtr = endNode;
  distance = distanceInput;
}
template
Edge<int>::Edge(Node<int>& startNode, Node<int>& endNode, uint distanceInput);

template <class T>
Node<T> Edge<T>::getStartNode(){
  return *startNodePtr;
}
template
Node<int> Edge<int>::getStartNode();

template <class T>
Node<T> Edge<T>::getEndNode(){
  return *endNodePtr;
}
template
Node<int> Edge<int>::getEndNode();

template <class T>
uint Edge<T>::getDistance(){
  return distance;
}
template
uint Edge<int>::getDistance();
