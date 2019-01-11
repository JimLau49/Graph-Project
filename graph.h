#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Node
{
	protected:
		int id;
		int value;
		int *connection;
		int current_connection;
		int size_of_connections;
		
	public:	
	
		
		Node(); 
		Node(int,int);
		~Node();
		Node(const Node&);
		int getID() {return id;}
		int getValue() {return value;}
		
		
		bool operator==(const Node&) const;
		friend ostream& operator << (ostream&, const Node&);
		
	
		void add_connection(int);
		void remove_connection(int);
		void displayConnections();
};


class Edge
{
	protected:
		int starting;
		int ending;
		
	public:
		Edge();
		Edge(Node&,Node&);	
		~Edge();
		Edge(const Edge&);
		int getStarting() {return starting;}
		int getEnding() {return ending;}

		bool operator==(const Edge&) const;
		friend ostream& operator << (ostream&, const Edge&);
		
};

class Graph
{
	protected:
		Node * nodelist; // points to dynamic array which contains the list of nodes
		Edge * edgelist; // points to dynamic array which contains the list of edges
		
		int size_nodelist;
		int size_edgelist;
		int current_size_nodelist;
		int current_size_edgelist;
	//	vector<Node> nodelist(int); //  if using vectors instead of dynamic arrays
	//	vector<Edge> edgelist(int);
	public:	
		int countNode();
		int countEdge();
		void display();
		
	
		Graph();
		Graph(int,int);	 
		Graph(const Graph&);		
		void addNode(Node);
		void addEdge(Edge);
		void removeNode(Node);
		void removeEdge(Edge,Node&,Node&);	
		void displayNodes();	
		virtual	void displayEdges();
		
		
		void searchEdge(Edge);
		void searchNode(Node);
		void searchByNodeValue(int);
};

class DirectedGraph : public Graph
{
	protected:
		
		
	public:
		DirectedGraph(const DirectedGraph&);
		DirectedGraph(int,int);
		virtual void displayEdges();
		
};

#endif

