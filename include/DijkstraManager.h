#ifndef DIJKSTRA_MANAGER_H
#define DIJKSTRA_MANAGER_H

#include "Graph.h"
#include "Path.h"
#include "MinPriorityQueue.h"

template <class T>
class DijkstraManager{
  Graph<T> graph;
  MinPriorityQueue<T> priorityQueue;
  std::vector<Node<T>> visitedVector;
public:
  DijkstraManager(Graph<T> graph, MinPriorityQueue<T> queue);
  Path<T> findShortestPathBetween(uint fstIndex, uint sndIndex);
  void addToQueue(Node<T> node);
  void updateInQueue(Node<T> node, uint distance);
  Path<T> createPath(Node<T> node);
  Node<T>* searchForVisited(Node<T>* node);
  void addToQueue(Node<T> node, uint distance);
};

#endif
