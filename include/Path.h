#ifndef PATH_H
#define PATH_H

#include "Graph.h"
#include <sstream>

template <class T>
class Path{
	std::vector<Node<T>*> nodes;
public:
	Path(Node<T>* nodePtr);
	void addNode(Node<T>* nodePtr);
	std::string toString();
};



template <class T>
Path<T>::Path(Node<T>* nodePtr){
	nodes.push_back(nodePtr);
}


template <class T>
void Path<T>::addNode(Node<T>* nodePtr){
	nodes.push_back(nodePtr);
}


template <class T>
std::string Path<T>::toString(){
	std::stringstream ss;
	for(int i=nodes.size()-1;i>=0;--i){
		ss<<nodes[i]->getIndex()<<" ";
	}
	return ss.str();
}


#endif
