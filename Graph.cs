using System.Collections.Generic;

/// <summary>
/// Base class for all graphs
/// </summary>
public class Graph
{
    bool bidirectional;
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
        bidirectional = true;
    }

    public Graph(bool bidirectional)
    {
        this.bidirectional = bidirectional;
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
        if (bidirectional)
            d.adjacent.Add(s);
    }
}