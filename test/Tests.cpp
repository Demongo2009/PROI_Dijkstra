#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/DijkstraManager.h"


TEST_CASE("Graph tests"){

  /*

  ---0---
  |  |1 |3
 5|  1--2-----
  |  |2 |   |
  |  3  |1  |
  | 1|  |   |1
  ---4--4----5
          1
  */
  Graph<int> graph= Graph<int>();
  int val1 =1;
  int val2 =2;
  int val3 =3;
  int val4 =4;
  int val5 =5;
  int val6 =6;

  graph.addNode(&val1);
  graph.addNode(&val2);
  graph.addNode(&val3);
  graph.addNode(&val4);
  graph.addNode(&val5);
  graph.addNode(&val6);

  SECTION("check adding node with contents to graph"){

    REQUIRE (*(graph.getNodes()[0]->getContents()) == val1);
    REQUIRE (*(graph.getNodes()[1]->getContents()) == val2);
    REQUIRE (*(graph.getNodes()[2]->getContents()) == val3);
    REQUIRE (*(graph.getNodes()[3]->getContents()) == val4);
    REQUIRE (*(graph.getNodes()[4]->getContents()) == val5);
    REQUIRE (*(graph.getNodes()[5]->getContents()) == val6);

  }

  int distance1 = 1;
  graph.addEdge(0,1,distance1);
  graph.addEdge(0,2,3);
  graph.addEdge(2,4,1);
  graph.addEdge(1,2,1);
  graph.addEdge(1,3,2);
  graph.addEdge(3,4,1);
  graph.addEdge(2,5,1);
  graph.addEdge(4,5,1);
  graph.addEdge(4,0,5);

  SECTION("check adding edges"){
    REQUIRE ((graph.getNodes()[0]->getEdges()[0].getEndNode()->getIndex()) == (graph.getNodes()[1]->getIndex()));
    REQUIRE ((graph.getNodes()[1]->getEdges()[0].getStartNode()->getIndex()) == (graph.getNodes()[0]->getIndex()));
    REQUIRE ((graph.getNodes()[0]->getEdges()[0].getDistance()) == distance1);
    REQUIRE ((graph.getNodes()[1]->getEdges()[0].getDistance()) == distance1);
  }

  DijkstraManager<int> dijkstraManager = DijkstraManager<int>(graph, MinPriorityQueue<int>());

  SECTION("check if dijkstra worikng"){
    REQUIRE(dijkstraManager.findShortestPathBetween(4,0).toString() == "4 2 1 0 ");
  }



}
