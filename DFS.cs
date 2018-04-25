using System.Collections.Generic;

class GraphDFS : Graph
{
	// A function which starts the recursion
    public bool HasPathRecursive(int source, int destination)
    {
        Node s = GetNode(source);
        Node d = GetNode(destination);
        HashSet<int> visited = new HashSet<int>();
		
        return HasPathRecursive(s, d, visited);
    }

	// A helper function that is called recursively
    bool HasPathRecursive(Node source, Node destination, HashSet<int> visited)
    {
        if (visited.Contains(source.ID))
            return false;

        visited.Add(source.ID);

        if (source == destination)
            return true;

		// Call the recursive method for each adjacent Node
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

            if (visited.Contains(c.ID))
				continue;

			visited.Add(c.ID);
			
			// Push all adjacent Nodes onto the stack
			for (int i = 0; i < c.adjacent.Count; i++)
			{
				stack.Push(c.adjacent[i]);
			}
        }

        return false;
    }
}