#include <unordered_map>
#include <set>

using namespace std;

struct Node
{
    set<Node*> adjacent;
    int ID;
};

class Graph
{
private:
    bool directed;
    unordered_map<int, Node> nodeLookup;

protected:
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

    void addEdge(int u, int v)
    {
        Node* source = getNode(u);
        Node* destination = getNode(v);
        source->adjacent.insert(destination);
        if (!directed)
            destination->adjacent.insert(source);
    }
};
