
#include <stdint.h>
#include <iostream>

#include "../include/Graph.h"
#include "../include/MinPriorityQueue.h"
#include "../include/DijkstraManager.h"
#include <string>



int main(){
	Graph<float> g= Graph<float>();
	float val1 =1;
	float val2 =2;
	float val3 =3;
	float val4 =4;
	float val5 =5;
	float val6 =6;


	g.addNode(&val1);
	g.addNode(&val2);
	g.addNode(&val3);
	g.addNode(&val4);
	g.addNode(&val5);
	g.addNode(&val6);
	g.addEdge(0,1,1);
	g.addEdge(0,2,3);
	g.addEdge(2,4,1);
	g.addEdge(1,2,1);
	g.addEdge(1,3,2);
	g.addEdge(3,4,1);
	g.addEdge(2,5,1);
	g.addEdge(4,5,1);
	g.addEdge(4,0,5);

	DijkstraManager<float> dm = DijkstraManager<float>(g, MinPriorityQueue<float>());
	std::cout<< dm.findShortestPathBetween(3, 0).toString();
}