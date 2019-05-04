#include <iostream>
#include <typeinfo>


#include "../include/Node.h"
#include <vector>


template <class T>
Node<T>::Node(T nodeContents, uint index){
  nodeContents = &nodeContents;
  index = index;
}
template
Node<int>::Node(int nodeContents, uint index);

template <class T>
std::vector<Node<T>> Node<T>::getAdjacentNodes(){
  std::vector<Node> nodes;
  for(Edge<T> edge: edges){
    nodes.push_back(*edge.getStartNode());
    nodes.push_back(*edge.getEndNode());
  }
  return nodes;
}
template
std::vector<Node<int>> Node<int>::getAdjacentNodes();

template <class T>
std::vector<Edge<T>> Node<T>::getEdges(){
  return edges;
}
template
std::vector<Edge<int>> Node<int>::getEdges();

template <class T>
void Node<T>::addEdge(Edge<T> edge){
  edges.push_back(edge);
}
template
void Node<int>::addEdge(Edge<int> edge);

template <class T>
uint Node<T>::getIndex(){
  return index;
}
template
uint Node<int>::getIndex();

template <class T>
void Node<T>::setContents(T* contents){
  nodeContents = contents;
}
template
void Node<int>::setContents(int* contents);

template <class T>
T* Node<T>::getContents(){
  return nodeContents;
}
template
int* Node<int>::getContents();

template <class T>
bool Node<T>::isVisited(){
  return visited;
}
template
bool Node<int>::isVisited();

template <class T>
bool Node<T>::isInQueue(){
  return inQueue;
}
template
bool Node<int>::isInQueue();

template <class T>
void Node<T>::setVisited(bool b){
  visited = b;
}
template
void Node<int>::setVisited(bool b);

template <class T>
void Node<T>::setInQueue(bool b){
  inQueue = b;
}
template
void Node<int>::setInQueue(bool b);

template <class T>
void Node<T>::setParentNode(Node* parentNodeInput){
  parentNode = parentNodeInput;
}
template
void Node<int>::setParentNode(Node* parentNodeInput);

template <class T>
Node<T>* Node<T>::getParentNode(){
  return parentNode;
}
template
Node<int>* Node<int>::getParentNode();
