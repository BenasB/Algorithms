#include <iostream>
#include <Graph.cpp>
#include <stack>
#include <set>

using namespace std;

class GraphDFS : public Graph
{
private:
    bool isReachableRecursive(Node source, Node destination, set<int>& visited)
    {
        if (visited.find(source.ID) != visited.end())
            return false;

        visited.insert(source.ID);

        if (source.ID == destination.ID)
            return true;

        for (auto i : source.adjacent)
        {
            if (isReachableRecursive(*i, destination, visited))
                return true;
        }

        return false;
    }

public:

    GraphDFS (bool direct) : Graph (direct) {}

    bool isReachableRecursive(int source, int destination)
    {
        Node* c = getNode(source);
        Node* d = getNode(destination);
        set<int> visited;
        return isReachableRecursive(*c, *d, visited);
    }

    bool isReachableIterative(int source, int destination)
    {
        Node* c = getNode(source);
        Node* d = getNode(destination);
        set<int> visited;
        stack<Node*> s;

        s.push(c);

        while (!s.empty())
        {
            c = s.top();
            s.pop();

            if (c->ID == d->ID)
                return true;

            if (visited.find(c->ID) != visited.end())
                continue;

            visited.insert(c->ID);

            for(auto i : c->adjacent)
            {
                s.push(i);
            }
        }

        return false;
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

    cout << graph.isReachableIterative(1, 4) << endl;
}
