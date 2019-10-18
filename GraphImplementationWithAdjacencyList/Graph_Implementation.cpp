#include "Graph_Implementation_Header.h"

Node::Node(int _Source, int _Destination)
	:Source(_Source), Destination(_Destination), NextNode(NULL) {

}

AdjacencyList::AdjacencyList()
	: ListHead(NULL) {

}

Graph::Graph(int _NodesNumber)
	: NodesNumber(_NodesNumber) {
	ListsVector.resize(_NodesNumber);
	for (int i = 0; i < _NodesNumber; ++i) {
		ListsVector[i] = new AdjacencyList();
		ListsVector[i]->ListHead = NULL;
	}
}

void Graph::AddEdge(int _Source, int _Destination) {
	Node* TempNode = new Node(_Source, _Destination);
	TempNode->NextNode = ListsVector[_Source]->ListHead;
	ListsVector[_Source]->ListHead = TempNode;
	/*if (_Source == _Destination)
		return;
	TempNode = new Node(_Destination, _Source);
	TempNode->NextNode = ListsVector[_Destination]->ListHead;
	ListsVector[_Destination]->ListHead = TempNode;*/
}

void Graph::PrintGraph() {
	AdjacencyList* AdjListPtr;
	for (int i = 0; i < NodesNumber; ++i) {
		AdjListPtr = ListsVector[i];
		cout << "Node " << i << ": ";
		Node* temp = AdjListPtr->ListHead;
		while (temp) {
			cout << temp->Destination << ", ";
			temp = temp->NextNode;
		}
		cout << endl;
	}
	cout << "\n" << endl;
}

void Graph::OutEdges(int _Node) {
	cout << "\nOut nodes from node " << _Node << ": ";
	Node* TempNode = ListsVector[_Node]->ListHead;
	while (TempNode) {
		cout << TempNode->Destination << ", ";
		TempNode = TempNode->NextNode;
	}
	cout << "\n" << endl;
}


void Graph::InEdges(int _Node) {
	cout << "\nNodes getting into node " << _Node << ": ";
	AdjacencyList* AdjListPtr;
	for (int i = 0; i < NodesNumber; ++i) {
		AdjListPtr = ListsVector[i];
		Node* TempNode = AdjListPtr->ListHead;
		while (TempNode) {
			if (TempNode->Destination == _Node)
				cout << TempNode->Source << ", ";
			TempNode = TempNode->NextNode;
		}

	}
	cout << "\n" << endl;
}
