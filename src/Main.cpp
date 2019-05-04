
#include <stdint.h>
#include <iostream>

#include "../include/Graph.h"
#include "../include/MinPriorityQueue.h"
#include "../include/DijkstraManager.h"




int main(){
  Graph<int> g= Graph<int>();
  g.addNode(1);
  g.addNode(2);
  g.addNode(3);
  g.addNode(4);
  g.addNode(5);
  g.addEdge(1,2,2);
  g.addEdge(1,3,1);
  g.addEdge(3,2,1);
  g.addEdge(3,4,2);
  g.addEdge(2,4,3);
  g.addEdge(3,5,3);
  g.addEdge(4,5,2);

  DijkstraManager<int> dm = DijkstraManager<int>(g, MinPriorityQueue<int>());
  std::cout<< dm.findShortestPathBetween(1, 5).toString();
}
