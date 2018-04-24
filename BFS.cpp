#include <iostream>
#include <Graph.cpp>
#include <set>
#include <queue>

using namespace std;

class GraphBFS : public Graph
{
public:
    GraphBFS(bool directed) : Graph(directed) {}

    bool isReachable(int source, int destination)
    {
        Node* s = getNode(source);
        Node* d = getNode(destination);
        set<int> visited;
        queue<Node*> Q;

        Q.push(s);

        while(!Q.empty())
        {
            Node* c = Q.front();
            Q.pop();

            if (c->ID == d->ID)
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
