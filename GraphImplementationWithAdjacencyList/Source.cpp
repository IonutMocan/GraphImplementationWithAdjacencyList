// Graph implementation using Linked Lists


#include "Graph_Implementation_Header.h"

void main() {
	Graph g(4);
	g.AddEdge(0, 1);
	g.AddEdge(2, 1);
	g.AddEdge(1, 3);
	g.AddEdge(1, 4);

	g.PrintGraph();

	g.OutEdges(1);
	g.InEdges(1);
}