using System.Collections.Generic;

class GraphDijkstra : WeightedGraph
{
    public int pathDistance(int start, int destination)
    {
        Node s = GetNode(start);
        Dictionary<int, int> distances = new Dictionary<int, int>();
        PriorityQueue<Neighbour> priorityQueue = new PriorityQueue<Neighbour>();

        foreach (var n in nodeLookup)
        {
           distances[n.Value.ID] = int.MaxValue; 
        }

        priorityQueue.Enqueue(new Neighbour(s, 0));
        distances[s.ID] = 0;

        while (!priorityQueue.Empty)
        {
            Neighbour top = priorityQueue.Dequeue();

            foreach (Neighbour neighbour in top.Node.adjacent)
            {
                int newDistance = distances[top.Node.ID] + neighbour.Weight;

                if (distances[neighbour.Node.ID] > newDistance)
                {
                    distances[neighbour.Node.ID] = newDistance;
                    priorityQueue.Enqueue(new Neighbour(neighbour.Node, newDistance));
                }
            }
        }

        if (distances.ContainsKey(destination))
            return distances[destination];
        else
            return int.MaxValue;
    }
}