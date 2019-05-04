#include <iostream>
#include <typeinfo>

#include <sstream>

#include "../include/Path.h"
#include <vector>
#include <string>



template <class T>
Path<T>::Path(Node<T>* nodePtr){
  nodes.push_back(nodePtr);
}
template
Path<int>::Path(Node<int>* nodePtr);

template <class T>
void Path<T>::addNode(Node<T>* nodePtr){
  nodes.push_back(nodePtr);
}
template
void Path<int>::addNode(Node<int>* nodePtr);

template <class T>
std::string Path<T>::toString(){
  std::stringstream ss;
  for(Node<T>* nodePtr: nodes){
    ss<<nodePtr->getIndex()<<" ";
  }
  return ss.str();
}
template
std::string Path<int>::toString();
