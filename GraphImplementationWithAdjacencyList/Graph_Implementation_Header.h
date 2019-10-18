#ifndef GRAPH_IMPLEMENTATION
#define GRAPH_IMPLEMENTATION
//#include "GraphImplementation.cpp"

#include <iostream>
#include <vector>


using namespace std;

class Node {
public:
	int Source;
	int Destination;
	Node* NextNode;
	Node(int _Source, int _Destination);
};

class AdjacencyList {
public:
	Node* ListHead;
	AdjacencyList();
};

class Graph {
public:
	int NodesNumber;
	vector <AdjacencyList*> ListsVector;
	Graph(int _NodesNumber);
	void AddEdge(int _Source, int _Destination);
	void PrintGraph();
	void OutEdges(int _Node);
	void InEdges(int _Node);
};

#endif 

