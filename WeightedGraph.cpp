#include <iostream>
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
protected:
    bool directed;
    unordered_map<int, Node> nodeLookup;

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

    void print()
    {
        for(auto i : nodeLookup)
        {
            cout << i.first << " connects with: " << '\n';
            for(auto j : i.second.adjacent)
            {
                cout << j->ID << '\n';
            }
            cout << '\n';
        }
    }
};

class WeightedGraph : public Graph
{
private:
    typedef pair<Node*, int> pni;
    unordered_map<int, pni> nodeLookup;

protected:
    pni getNode(int id)
    {
        if (nodeLookup.find(id) != nodeLookup.end())
            return nodeLookup[id];
        else
        {
            // Create new and return
        }
    }

public:
    // Implement addEdge
};

int main()
{

}
