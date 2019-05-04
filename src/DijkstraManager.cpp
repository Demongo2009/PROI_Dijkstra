#include <iostream>
#include <typeinfo>


#include "../include/DijkstraManager.h"
#include <vector>

template <class T>
DijkstraManager<T>::DijkstraManager(Graph<T> graphInput, MinPriorityQueue<T> queue){
  graph = graphInput;
  priorityQueue = queue;
}
template
DijkstraManager<int>::DijkstraManager(Graph<int> graphInput, MinPriorityQueue<int> queue);

template <class T>
Path<T> DijkstraManager<T>::findShortestPathBetween(uint startIndex, uint destinationIndex){
  std::vector<Node<T>> graphNodes = graph.getNodes();

  priorityQueue.insertDummy(PriorityDummy<Node<T>>(graphNodes[startIndex],0));
  Node<T> neighbourNode;
  Node<T> currentNode;
  Path<T> path;
  while(priorityQueue[FIRST_IN_QUEUE]){
    for(Edge<T> edge: priorityQueue[FIRST_IN_QUEUE].getEdges()){
      neighbourNode = edge.getEndNode();
      if(neighbourNode.getIndex()==destinationIndex){
        return createPath(neighbourNode);
      }

      if(!neighbourNode.isVisited()){
        currentNode = edge.getStartNode();
        neighbourNode.setParentNode(&currentNode);
        uint distanceSoFar = priorityQueue[FIRST_IN_QUEUE].getPriority();
        uint newDistance = distanceSoFar + edge.getDistance();
        if(!neighbourNode.isInQueue()){
          addToQueue(neighbourNode,newDistance);
        }else{
          if(priorityQueue[searchForElement(neighbourNode)]<newDistance){
            updateInQueue(neighbourNode,newDistance);
          }
        }
      }
    }
    visitedVector.push_back(priorityQueue.extractMinimum());
  }
  return Path<T>(nullptr);
}
template
Path<int> DijkstraManager<int>::findShortestPathBetween(uint startIndex, uint destinationIndex);

template <class T>
void DijkstraManager<T>::updateInQueue(Node<T> node, uint distance){
  uint nodeIndex = node.getIndex();
  uint dummyIndexInQueue = priorityQueue.searchForElement(nodeIndex);
  if(dummyIndexInQueue==0){
    return;
  }
  if(!priorityQueue.decreaseDummyPriority(dummyIndexInQueue,distance)){
    return;
  }
}
template
void DijkstraManager<int>::updateInQueue(Node<int> node, uint distance);

template <class T>
Path<T> DijkstraManager<T>::createPath(Node<T> node){
  Path<T> path = Path<T>();
  path.addNode(node);
  Node<T>* parentNode = node.getParentNode();
  Node<T>* vistitedNode = searchForVisited(parentNode);
  while (vistitedNode) {
    path.addNode(*vistitedNode);
    parentNode = vistitedNode->parentNode;
    vistitedNode = searchForVisited(parentNode);
  }
  return path;
}
template
Path<int> DijkstraManager<int>::createPath(Node<int> node);

template <class T>
Node<T>* DijkstraManager<T>::searchForVisited(Node<T>* node){
  for(Node<T> visitedNode: visitedVector){
    if(visitedNode.getIndex()==node.getIndex()){
      return &visitedNode;
    }
  }
  return nullptr;
}
template
Node<int>* DijkstraManager<int>::searchForVisited(Node<int>* node);

template <class T>
void DijkstraManager<T>::addToQueue(Node<T> node, uint distance){
  PriorityDummy<T> newDummy = new PriorityDummy<Node<T>>(node,distance);
  priorityQueue.insertDummy(newDummy);
}

template
void DijkstraManager<int>::addToQueue(Node<int> node, uint distance);
