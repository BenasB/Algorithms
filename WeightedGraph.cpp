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
    bool directed;

protected:
    std::unordered_map<int, Node> nodeLookup;
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
