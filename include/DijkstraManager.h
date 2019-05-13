#ifndef DIJKSTRA_MANAGER_H
#define DIJKSTRA_MANAGER_H

#include "Graph.h"
#include "Path.h"
#include "MinPriorityQueue.h"

template <class T>
class DijkstraManager{
	Graph<T> graph; //graph object
	MinPriorityQueue<T> priorityQueue; // priority queue object
	std::vector<Node<T>> visitedVector; // vector of already visited nodes
public:
	DijkstraManager(Graph<T> graph, MinPriorityQueue<T> queue); //constructor
	Path<T> findShortestPathBetween(uint fstIndex, uint sndIndex); // finds and returns path
//consisting of nodes in order form fst to snd using dijkstra algorithm
private:
	void addToQueue(Node<T> node); // adds node to queue
	void updateInQueue(Node<T>* node, uint distance); // updates node in queue with given distance
	Path<T> createPath(Node<T>* node); // creates path form end node
	Node<T>* searchForVisited(Node<T>* node); //searches for given visited node
	void addToQueue(Node<T>* node, uint distance); //adds node to queue with given distance

	Node<T> *chooseEdgeNode(Node<T> *currentNode, Edge<T> &edge) ; // chooses node for edge which isnt a current node

	void processNode(Node<T> *neighbourNode, PriorityDummy<T> *currentDummy,  Node<T> *currentNode, Edge<T> &edge); // adds node to queue or updates it with new distance
};


template <class T>
DijkstraManager<T>::DijkstraManager(Graph<T> graphInput, MinPriorityQueue<T> queue){
	graph = graphInput;
	priorityQueue = queue;
}

template <class T>
Path<T> DijkstraManager<T>::findShortestPathBetween(uint startIndex, uint destinationIndex){
	// seting all variables and structures
	std::vector<Node<T>*> graphNodes = graph.getNodes();
	priorityQueue.insertNode(graphNodes[startIndex],0);
	Node<T>* neighbourNode;
	PriorityDummy<T>* currentDummy = priorityQueue.extractMinimum();
	Node<T>* currentNode= currentDummy->getNode();
	Path<T> path(nullptr);

	while(&currentNode){
		// checks all edges
		for(Edge<T> edge: currentNode->getEdges()){
			neighbourNode = chooseEdgeNode(currentNode, edge);

			if(!neighbourNode->isVisited()){

				processNode(neighbourNode, currentDummy, currentNode, edge);
			}
		}
		
		// chooses new dummy and node to process
		currentNode->setVisited(true);
		visitedVector.push_back(*currentNode);
		PriorityDummy<T>* pointer;
		if( pointer = priorityQueue.extractMinimum()){

			currentDummy = pointer;
			currentNode= currentDummy->getNode();
			if(currentNode->getIndex()==destinationIndex){
				path = createPath(currentNode);
				return path;
			}
		}else{
			break;
		}
	}
	return path;
}

template <class T>
void DijkstraManager<T>::processNode(Node<T> *neighbourNode, PriorityDummy<T> *currentDummy,  Node<T> *currentNode,
								  Edge<T> &edge) {
	uint distanceSoFar = currentDummy->getPriority();
	uint newDistance = distanceSoFar + edge.getDistance();

	if (!neighbourNode->isInQueue()) {
		neighbourNode->setParentNode(currentNode);
		addToQueue(neighbourNode, newDistance);
	} else {
		if (priorityQueue.searchForDummy(neighbourNode)->getPriority() > newDistance) {
			neighbourNode->setParentNode(currentNode);
			updateInQueue(neighbourNode, newDistance);
		}
	}
}

template <class T>
Node<T> *DijkstraManager<T>::chooseEdgeNode(Node<T> *currentNode, Edge<T> &edge) {
	Node<T> *neighbourNode;
	if (edge.getEndNode()->getIndex() == currentNode->getIndex()) {
		neighbourNode = edge.getStartNode();
	} else {
		neighbourNode = edge.getEndNode();
	}
	return neighbourNode;
}

template <class T>
void DijkstraManager<T>::updateInQueue(Node<T>* node, uint distance){
	PriorityDummy<T>* dummyInQueue = priorityQueue.searchForDummy(node);
	if(!dummyInQueue){
		return;
	}
	priorityQueue.decreaseDummyPriority(priorityQueue.getDummyIndex(*dummyInQueue),distance);
}

template <class T>
Path<T> DijkstraManager<T>::createPath(Node<T>* node){
	Path<T> path = Path<T>(node);
	Node<T>* parentNodePtr = node->getParentNode();
	while (parentNodePtr) {
		path.addNode(parentNodePtr);
		parentNodePtr = parentNodePtr->getParentNode();
	}
	return path;
}

template <class T>
Node<T>* DijkstraManager<T>::searchForVisited(Node<T>* node){
	for(Node<T> visitedNode: visitedVector){
		if(visitedNode.getIndex()==node->getIndex()){
			return &visitedNode;
		}
	}
	return nullptr;
}

template <class T>
void DijkstraManager<T>::addToQueue(Node<T>* node, uint distance){

	priorityQueue.insertNode(node,distance);
}


#endif
