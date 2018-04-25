// A base Weighted Graph class which is included in weighted algorithms
// Uses a different Node structure than a (unweighted) Graph

#include <unordered_map>
#include <set>

struct Node;

typedef std::pair<Node*, int> pni;

struct Node
{
    std::set<pni> adjacent;
    int ID;
};

class WeightedGraph
{
private:
	// Determines if the graph is directed
	// (edges are one-way)
    bool directed;

protected:
    // Keeps track of nodes based on IDs
	std::unordered_map<int, Node> nodeLookup;
    
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
    WeightedGraph (bool direct) : directed(direct) {}

    void addEdge(int source, int destination, int weight)
    {
        Node* s = getNode(source);
        Node* d = getNode(destination);
		
        s->adjacent.insert(pni(d, weight));
        if (!directed)
            d->adjacent.insert(pni(s, weight));
    }
};
