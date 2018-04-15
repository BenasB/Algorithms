using System.Collections.Generic;

class GraphBFS : Graph
{
    public bool HasPath (int source, int destination)
    {
        Node s = GetNode(source);
        Node d = GetNode(destination);

        HashSet<int> visited = new HashSet<int>();
        Queue<Node> nextToVisit = new Queue<Node>();

        nextToVisit.Enqueue(s);

        while(nextToVisit.Count != 0)
        {
            Node node = nextToVisit.Dequeue();

            if (node == d)
                return true;

            if (visited.Contains(node.ID))
                continue;

            visited.Add(node.ID);

            for (int i = 0; i < node.adjacent.Count; i++)
            {
                nextToVisit.Enqueue(node.adjacent[i]);
            }
        }

        return false;
    }
}
