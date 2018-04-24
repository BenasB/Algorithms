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
    bool directed;
    std::unordered_map<int, Node> nodeLookup;

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

    void addEdge(int source, int destination)
    {
        Node* s = getNode(source);
        Node* d = getNode(destination);
        s->adjacent.insert(d);
        if (!directed)
            d->adjacent.insert(s);
    }
};
