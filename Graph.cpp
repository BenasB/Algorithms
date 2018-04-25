// A base Graph class which is included in unweighted algorithms

#include <unordered_map>
#include <set>

struct Node
{
    std::set<Node*> adjacent;	
    int ID;
};

class Graph
{
private:
	// Determines if the graph is directed
	// (edges are one-way)
    bool directed;
	
	// Keeps track of nodes based on IDs
    std::unordered_map<int, Node> nodeLookup;

protected:
	// Returns node from nodeLookup
	// Creates a new one if it doesn't exist
    Node* getNode(int id)
    {
        if (nodeLookup.find(id) != nodeLookup.end())
            return &nodeLookup[id];
        else
        {
            Node newNode;
            newNode.ID = id;
            nodeLookup[id] = newNode;
            return &nodeLookup[id];
        }
    }

public:
    Graph(bool direct) : directed(direct) {}

    void addEdge(int source, int destination)
    {
        Node* s = getNode(source);
        Node* d = getNode(destination);
		
        s->adjacent.insert(d);
        if (!directed)
            d->adjacent.insert(s);
    }
};
