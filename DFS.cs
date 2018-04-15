using System.Collections.Generic;

class GraphDFS : Graph
{
    public bool HasPath(int source, int destination)
    {
        Node s = GetNode(source);
        Node d = GetNode(destination);
        HashSet<int> visited = new HashSet<int>();
        return HasPath(s, d, visited);
    }

    bool HasPath(Node source, Node destination, HashSet<int> visited)
    {
        if (visited.Contains(source.ID))
            return false;

        visited.Add(source.ID);

        if (source == destination)
            return true;

        for (int i = 0; i < source.adjacent.Count; i++)
        {
            if (HasPath(source.adjacent[i], destination, visited))
                return true;
        }

        return false;
    }
}