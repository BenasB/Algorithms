#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>

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

class GraphBFS : public Graph
{
public:
    GraphBFS(bool directed) : Graph(directed) {}

    bool isReachable(int u, int v)
    {
        Node* source = getNode(u);
        Node* destination = getNode(v);
        set<int> visited;
        queue<Node*> Q;

        Q.push(source);

        while(!Q.empty())
        {
            Node* c = Q.front();
            Q.pop();

            if (c->ID == destination->ID)
                return true;

            if (visited.find(c->ID) != visited.end())
                continue;

            visited.insert(c->ID);

            for(auto i : c->adjacent)
            {
                Q.push(i);
            }
        }

        return false;
    }
};

int main()
{
    GraphBFS graph(false);

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

    cout << graph.isReachable(8, 10) << endl;
}
