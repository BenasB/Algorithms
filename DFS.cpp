#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct Node
{
    vector<Node*> adjacent;
    int ID;

    bool operator==(const Node& other)
    {
        return this->ID == other.ID;
    }
};

struct Graph
{
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

    void addEdge(int u, int v)
    {
        Node* source = getNode(u);
        Node* destination = getNode(v);
        source->adjacent.push_back(destination);
        destination->adjacent.push_back(source);
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

    bool DFS(Node source, Node destination, set<int>& visited)
    {
        if (visited.find(source.ID) != visited.end())
            return false;

        visited.insert(source.ID);

        if (source == destination)
            return true;

        for (auto i : source.adjacent)
        {
            if (DFS(*i, destination, visited))
                return true;
        }

        return false;
    }

    bool DFS(int u, int v)
    {
        Node* source = getNode(u);
        Node* destination = getNode(v);
        set<int> visited;
        return DFS(*source, *destination, visited);
    }
};

int main()
{
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(3, 2);
    graph.addEdge(3, 5);
    graph.addEdge(5, 7);
    graph.addEdge(5, 4);
    graph.addEdge(2, 4);
    graph.addEdge(1, 6);

    cout << graph.DFS(1, 4) << endl;
}
