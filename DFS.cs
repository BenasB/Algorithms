using System.Collections.Generic;

class GraphDFS : Graph
{
    public bool HasPathRecursive(int source, int destination)
    {
        Node s = GetNode(source);
        Node d = GetNode(destination);
        HashSet<int> visited = new HashSet<int>();
        return HasPathRecursive(s, d, visited);
    }

    bool HasPathRecursive(Node source, Node destination, HashSet<int> visited)
    {
        if (visited.Contains(source.ID))
            return false;

        visited.Add(source.ID);

        if (source == destination)
            return true;

        for (int i = 0; i < source.adjacent.Count; i++)
        {
            if (HasPathRecursive(source.adjacent[i], destination, visited))
                return true;
        }

        return false;
    }

    public bool HasPathIterative(int source, int destination)
    {
        Node c = GetNode(source);
        Node d = GetNode(destination);
        Stack<Node> stack = new Stack<Node>();
        HashSet<int> visited = new HashSet<int>();
        stack.Push(c);

        while (stack.Count != 0)
        {
            c = stack.Pop();

            if (c == d)
                return true;

            if (!visited.Contains(c.ID))
            {
                visited.Add(c.ID);
                for (int i = 0; i < c.adjacent.Count; i++)
                {
                    stack.Push(c.adjacent[i]);
                }
            }
        }

        return false;
    }
}