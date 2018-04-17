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

class GraphDFS : public Graph
{
private:
    bool isReachable(Node source, Node destination, set<int>& visited)
    {
        if (visited.find(source.ID) != visited.end())
            return false;

        visited.insert(source.ID);

        if (source.ID == destination.ID)
            return true;

        for (auto i : source.adjacent)
        {
            if (isReachable(*i, destination, visited))
                return true;
        }

        return false;
    }

public:

    GraphDFS (bool direct) : Graph (direct) {}

    bool isReachable(int u, int v)
    {
        Node* source = getNode(u);
        Node* destination = getNode(v);
        set<int> visited;
        return isReachable(*source, *destination, visited);
    }
};

int main()
{
    GraphDFS graph(false);
    graph.addEdge(1, 2);
    graph.addEdge(3, 2);
    graph.addEdge(3, 5);
    graph.addEdge(5, 7);
    graph.addEdge(5, 4);
    graph.addEdge(2, 4);
    graph.addEdge(1, 6);
    graph.addEdge(8, 9);
    graph.addEdge(9, 10);
    graph.addEdge(10, 8);

    cout << graph.isReachable(7, 4) << endl;
}
