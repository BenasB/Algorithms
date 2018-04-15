using System.Collections.Generic;

public class Graph
{
    public bool Bidirectional { get; set; }

    Dictionary<int, Node> nodeLookup = new Dictionary<int, Node>();

    protected class Node
    {
        public int ID { get; private set; }
        public List<Node> adjacent = new List<Node>();

        public Node(int id)
        {
            ID = id;
        }
    }

    public Graph()
    {
        Bidirectional = true;
    }

    public Graph(bool bidirectional)
    {
        Bidirectional = bidirectional;
    }

    protected Node GetNode(int id)
    {
        if (nodeLookup.ContainsKey(id))
            return nodeLookup[id];
        else
        {
            Node newNode = new Node(id);
            nodeLookup[id] = newNode;
            return newNode;
        }
    }

    public void AddEdge(int start, int destination)
    {
        Node s = GetNode(start);
        Node d = GetNode(destination);
        s.adjacent.Add(d);
        if (Bidirectional)
            d.adjacent.Add(s);
    }
}