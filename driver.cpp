#include <iostream>
#include <string>
#include <vector>
#include "graph.h"

using namespace std;




int main()
{
	// Undirected graph created by its constructor
	Graph g (3,3);
	
	// Call to Node constructor
	Node d0 (1,100);
	Node d1 (2,200);
	Node d2 (3,300);
	Node d3 (4,400);
	Node d4 (5,500);
	Node d5 (6,600);
	

	// Call to Edge constructor
	Edge e0(d0,d1);
	Edge e1(d0,d2);
	Edge e2(d1,d2);
	Edge e3(d2,d3);
	
	
	
	// Adding nodes into graph g
	g.addNode(d0);
	g.addNode(d1);
	g.addNode(d2);
	g.addNode(d3);
	g.addNode(d4);
	g.addNode(d5);


	// If a node is added to the graph, it CANNOT be re-added
	g.addNode(d3);
	
	
	// Shows all the nodes currently in the graph
	g.displayNodes();
	
	cout << endl;
	
	
	
	// Removing nodes from the graph
	g.removeNode(d0); 
	g.removeNode(d1);
	g.removeNode(d3); 
	g.removeNode(d5);


	// Displaying nodelist after deleting 	
	g.displayNodes();
	
	cout << endl;


	// Searching for nodes in graph g
	g.searchNode(d3); // exists
	g.searchNode(d1); // does not exist
	
	cout << endl;
	
	// Searching in the graph if a node corresponds with a value of 400
	int b = 400;
	g.searchByNodeValue(b);
	

	// Adding Edges into graph g
	g.addEdge(e0);
	g.addEdge(e1);

	// An Edge CANNOT be re-add to the list if it is already present
	g.addEdge(e1);
	
	g.displayEdges();
	cout << endl;

	
	cout << endl;
	
	// displays connections created by the Edge constructor
	d0.displayConnections();
	d1.displayConnections();
	
	
	// deleting an edge from the graph
	g.removeEdge(e0,d0,d1); 
	
	//search edges
	g.searchEdge(e0); // does not exist
	g.searchEdge(e1); // exists
	
	// The connection is also no longer present between these two nodes
	d0.displayConnections();
	d1.displayConnections();
	 

	g.displayEdges();
	
	
	// Undirected Graph copy constructor invoked
	Graph g1 = g;
	
	// To test if the nodes from g are in g1
	g1.displayNodes();

/////////////////////////////////////////////////////////////	
/////////TESTING DIRECTED GRAPH /////////////////////////////	
/////////////////////////////////////////////////////////////

	DirectedGraph D(50,50);
	D.addEdge(e0);
	D.addEdge(e1);
	D.displayEdges();

	D.searchEdge(e1);
	

	D.addNode(d0);
	D.addNode(d1);
	D.addNode(d2);
	D.addNode(d3);

	D.removeNode(d0);
	D.removeNode(d1);	

	
	D.displayNodes();
	
	D.searchByNodeValue(300);
	
	DirectedGraph D1 = D;
	
	
		
return 0;
}
