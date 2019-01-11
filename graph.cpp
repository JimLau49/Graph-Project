#include <iostream>
#include <string>
#include <vector>
#include "graph.h"

using namespace std;


Node::Node()
{
	
	id = 0;
	value = 0;
	current_connection = 0;
	size_of_connections =30;
	connection = new int[size_of_connections];
}


Node::Node(int node_ID, int node_val)
{
	
	id = node_ID;
	value = node_val;
	current_connection = 0;
	size_of_connections = 30;
	connection = new int[size_of_connections];
}



Node::Node(const Node& n1)
{
	id = n1.id;
	value = n1.value;
}




bool Node::operator==(const Node &n1) const
{
	if (id == n1.id)
		{
		return true;
		}
	else
		return false;	
	
}

Node::~Node()
{
}

Edge::Edge()
{
	starting = 1000;
	ending = 1000;
}

Edge::Edge(Node& n1, Node& n2 )
{
	
	starting = n1.getID();
	ending = n2.getID();
	
	
	n1.add_connection(ending);
	n2.add_connection(starting);
}

void Node::add_connection(int nid)
{

	connection[current_connection] = nid;
	current_connection++;
}

void Node::remove_connection(int nid2)
{
	bool status;
	int a;
	for (int i=0 ; i < current_connection ; i++)
	{
			
		if (connection[i] = nid2)
		{
			status = true;
			a = i;
			break;
		}
		else 
			status = false;	
	}
	if (status == true)
	{
			
		for (int j=a ; j<=current_connection; j++ )
	 		{
	 			connection[j] = connection[j+1];
			}
		current_connection--;
	}
	else
		cout << "cannot remove connection" << endl;				
			
}
	
void Node::displayConnections()
{
	cout << "printing Node [" << this->getID() << "]'s connections: " << endl;
	for(int i=0; i < current_connection ; i++)
		cout << "Node: " <<  connection[i] << endl;	
}

Edge::~Edge()
{	
}

Edge::Edge(const Edge& E)
{
	starting = E.starting;
	ending = E.ending;
}

bool Edge::operator==(const Edge& E1) const
{
	if ((starting == E1.starting) && (ending == E1.ending))	
		return true;
	else
		return false;	
}

Graph::Graph()
{
	cout << " Default Undirected Graph Created" << endl;
	size_nodelist = 10;
	size_edgelist = 10;
	current_size_nodelist= 0;
	current_size_edgelist= 0;
	nodelist = new Node[size_nodelist];
	edgelist = new Edge[size_edgelist];
}

Graph::Graph(int nL,int eL)
{	
	cout << "Undirected Graph Created" << endl;
	size_nodelist = nL;
	size_edgelist = eL;
	current_size_nodelist= 0;
	current_size_edgelist= 0;
	nodelist = new Node[size_nodelist];
	edgelist = new Edge[size_edgelist];
}

Graph::Graph(const Graph & g1)
{
	cout << "Undirected Graph Copy-Constructor" << endl;
	current_size_nodelist= g1.current_size_nodelist;
	current_size_edgelist= g1.current_size_edgelist;
	nodelist = g1.nodelist;
	edgelist = g1.edgelist;
}

void Graph::addNode(Node n1)
{
	 bool status;
	 
	 current_size_nodelist++;
	 for (int i=1; i <= current_size_nodelist ; i++)
	 {
	 	
	 	if(nodelist[i] == n1) // invokes overloaded == operator , could also use (nodelist[i].getID() == n1.getID()) 
	 	{
	 		status = true;
	 	
	 		break;
		}
	 	else
	 	{
	
	 		status = false;
						
				
			
		}
	 }
	 
	 if (status == true)
	 {
	 	current_size_nodelist--;
	 	cout << "the Node is already on the list" << endl;
	 	return;
	 }
	 
	 else
	 {
	 	nodelist[current_size_nodelist] = n1;
	 	cout << "Node successfully added to the list " << endl;
	 
	 	return;
	 }
	 	
}

void Graph::displayNodes()
{
	cout << endl;
	cout << "displaying Nodes in the graph: " <<endl;
	for (int j=1; j <= current_size_nodelist ; j++)
	{
		cout << "Node ID: " <<  nodelist[j].getID() << " , Node value: " << nodelist[j].getValue()  << endl;
		
	}	
	cout << endl;
}

void Graph::addEdge(Edge e1)
{
	
	bool status;
	 
	 current_size_edgelist++;
	 for (int i=1; i <= current_size_edgelist ; i++)
	 {
	 	if (edgelist[i] ==  e1)
	 	{
	 		status = true;
	 	
	 		break;
		}
	 	else
	 	{
	 		status = false;
		
						
			
		}
	 }
	 
	 if (status == true)
	 {
	 	current_size_edgelist--;
	 	cout << "the Edge is already on the list" << endl;
	 }
	 
	 if (status == false)
	 {
	 	edgelist[current_size_edgelist] = e1;
	 	cout << "Edge successfully added to the list" << endl;
	 	// cout << "Current size  edgelist = " << current_size_edgelist << endl; // debug purposes only
	 }
}

void Graph::displayEdges()
{
	cout << endl;
	cout << "displaying edges in the graph: " << endl;
	for (int x=1; x<= current_size_edgelist; x++)
	{
		cout << "Edge " << x << " :the Edge is between Nodes " << edgelist[x].getStarting();
		cout << " and " << edgelist[x].getEnding();
		cout << endl;
	 } 
}

void Graph::removeNode(Node n2)
{
	bool status; 
	
	

	
	for (int i=1; i <= current_size_nodelist ; i++)
	{	
	 	
	 	
	 	if (nodelist[i] ==  n2)
	 	{
	 		
	 		for (int j=i ; j<=current_size_nodelist; j++ )
	 		{
	 			nodelist[j] = nodelist[j+1];
			}
			status = true;
			break;
			
		}
		
		else
		
		{
			status = false;
			
		}
	}
	
	
		if (status== true)
		{
			current_size_nodelist--;
			int a = current_size_nodelist;
			cout << "the Node has been removed, current size of the nodelist = " << current_size_nodelist <<endl; // possible error
		}
		
	
		else if(status == false) 
		{
			cout << "the Node was not removed as it was not on the list" <<endl;
		}
}


void Graph::removeEdge(Edge e2, Node& n1, Node& n2)
{
	bool status; 
	
	

	
	for (int i=1; i <= current_size_edgelist ; i++)
	 {
	 	
	 	
	 	if (edgelist[i] == e2)
	 	{
	 		
	 		for (int j=i ; j<=current_size_edgelist; j++ )
	 		{
	 			edgelist[j] = edgelist[j+1];
			}
			status = true;
			break;
			
		}
		
		else
			status = false;
			
	}
	
	
		if (status== true)
		{
			current_size_edgelist--;
			cout << "the Edge has been removed, current size of the edgelist = " << current_size_edgelist <<endl;
			n1.remove_connection(e2.getEnding());
			n2.remove_connection(e2.getStarting());
		}
		
	
		else if(status == false) 
		{
			cout << "the Edge was not removed as it was not on the list" <<endl;
		}
}



ostream& operator<<(ostream& output, const Edge& e1)
{
	
	output << "[between " << e1.starting << " and " << e1.ending << "]" << endl;
		
	
	return output;	
}

void Graph::searchEdge(Edge e)
{
	bool presance;
	for (int i=1 ; i<= current_size_edgelist; i++)
	{
		if (edgelist[i] == e)
		{
			presance = true;
			break;
		}
		
		else
		{
			presance = false;
					
		}
		
	}
	
	if (presance == true)
	{
		cout << "the Edge: " << e << "has been found on the graph" << endl;
	}
	
	else
	{
		cout << "the Edge: " << e << "has not been found on the graph" << endl;
	}
	
	cout << endl;
}

ostream& operator <<(ostream& output, const Node& n1)
{
	output << "[ Node_ID: " << n1.id << " , Node_value: " << n1.value << "]" << endl; 
	
	return output;
}



void Graph::searchNode(Node n1)
{
	bool presance;
	
		for (int i=1 ; i<= current_size_nodelist; i++)
		{
			if (nodelist[i] == n1)
			{
				presance = true;
				break;
			}
			
			else
			{
				presance = false;
				
			}
			
		}
		
		if(presance==true)
		{
			cout << "the Node: " << n1 << "has been found on the graph" << endl;
			
		}
		
		else
		{
			cout << "the Node: " << n1 << "has not been found on the graph" << endl;
		}
		
	cout << endl;
}

void Graph::searchByNodeValue(int integer)
{
	bool presance;
	int finder;



	for (int i=1 ; i <= current_size_nodelist; i++)
	{
		if (nodelist[i].getValue() == integer )
		{
			presance = true;
			finder = i;
			break;
		}
		
		else
		{
			presance = false;
		}
		
	}
	
	if (presance == true)
	{
		cout << "A Node with value: [" << integer << "] has been found on the graph" << endl;
		cout << "corresponds to: " <<nodelist[finder] << endl;
		
	}
	
	else
	{
		cout << "the Node value: " << integer << " has not been found on the graph" << endl;
	}
	
	cout << endl;
}

DirectedGraph::DirectedGraph(int nL, int eL) : Graph(nL,eL)
{
	cout << "Directed Graph Created" << endl;
}

void DirectedGraph::displayEdges()
{
	cout << endl;
	cout << "displaying edges in the graph: " << endl;
	for (int x=1; x<= current_size_edgelist; x++)
	{
		cout << "Edge " << x << " :the Edge is from Node: " << edgelist[x].getStarting();
		cout << " towards Node:	" << edgelist[x].getEnding();
		cout << endl;
	 } 
}

DirectedGraph::DirectedGraph(const DirectedGraph& d1)
{
	cout << "Directed Graph Copy-Constructor" << endl;
	current_size_nodelist= d1.current_size_nodelist;
	current_size_edgelist= d1.current_size_edgelist;
	nodelist = d1.nodelist;
	edgelist = d1.edgelist;
}

