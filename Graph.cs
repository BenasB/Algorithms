using System;
using System.Collections;
using System.Collections.Generic;

public class Graph
{
    Dictionary<int, Node> nodeLookup = new Dictionary<int, Node>();

    class Node
    {
        int id;
        public HashSet<Node> adjacent = new HashSet<Node>();

        private Node(int id)
        {
            this.id = id;
        }
    }

    Node GetNode(int id)
    {
        if (nodeLookup.ContainsKey(id))
            return nodeLookup[id];
        else
            throw new ArgumentOutOfRangeException("id", "A node with that id doesn't exist");
    }

    public void AddEdge(int start, int destination)
    {
        Node s = GetNode(start);
        Node d = GetNode(destination);
        s.adjacent.Add(d);
    }
}