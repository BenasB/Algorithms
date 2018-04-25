#include <iostream>
#include <WeightedGraph.cpp>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF 0x3f3f3f3f

class GraphDijkstra : public WeightedGraph
{
public:
    GraphDijkstra(bool direct) : WeightedGraph(direct) {}

    int pathDistance(int source, int destination)
    {
        Node* s = getNode(source);
        unordered_map<int, int> dist;

        // Elements in pair pni:
        // first: Node* (adjacent node)
        // second: int (cost)
        priority_queue<pni, vector<pni>, greater<pni>> pq;

		// Set all distances to INF
        for (auto i : nodeLookup)
            dist[i.first] = INF;

        pq.push(pni(s, 0));
        dist[s->ID] = 0;

        while (!pq.empty())
        {
            // Extract the minimum distance node
            Node* c = pq.top().first;
            pq.pop();

            for (auto i : c->adjacent)
            {
                // Get adjacent Node and weight to it from Node c
                Node* a = i.first;
                int w = i.second;

                // Calculate the new cost that it would take
                // to reach the adjacent Node
                int newCost = dist[c->ID] + w;

                if (dist[a->ID] > newCost)
                {
                    dist[a->ID] = newCost;

                    // Push an (new) element with the newly discovered weight
                    // to the priority queue
                    pq.push(pni(a, newCost));
                }
            }
        }

        // Protection against Nodes that don't exist
        if (dist.find(destination) == dist.end())
            return INF;
        else
            return dist[destination];
    }
};

int main()
{
	// Sample code
    GraphDijkstra graph(false);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(1, 2, 8);
    graph.addEdge(7, 6, 1);
    graph.addEdge(7, 8, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(8, 6, 6);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 5, 4);
    graph.addEdge(6, 5, 2);
    graph.addEdge(3, 5, 14);
    graph.addEdge(3, 4, 9);
    graph.addEdge(5, 4, 10);

    cout << graph.pathDistance(0, 4) << endl;
}
