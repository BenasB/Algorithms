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

    int dijkstra(int source, int destination)
    {
        Node* s = getNode(source);
        unordered_map<int, int> dist;
        priority_queue<pni, vector<pni>, greater<pni>> pq;

        for (auto i : nodeLookup)
            dist[i.first] = INF;

        pq.push(pni(s, 0));
        dist[s->ID] = 0;

        while (!pq.empty())
        {
            Node* n = pq.top().first;
            int w = pq.top().second;
            pq.pop();

            if (dist[n->ID] < w) continue;

            for (auto i : n->adjacent)
            {
                Node* m = i.first;
                int v = i.second;

                if (dist[m->ID] > dist[n->ID] + v)
                {
                    dist[m->ID] = dist[n->ID] + v;
                    pq.push(pni(m, dist[m->ID]));
                }
            }
        }

        return dist[destination];
    }
};

int main()
{
    GraphDijkstra graph(false);

    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 4, 3);

    cout << graph.dijkstra(4, 1) << endl;
}
