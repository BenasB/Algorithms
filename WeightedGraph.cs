using System;
using System.Collections.Generic;

/// <summary>
/// Base class for all graphs
/// </summary>
public class WeightedGraph
{
	// Determines if the graph is two-way
    bool bidirectional;
	
	// Used to look up nodes based on IDs
    protected Dictionary<int, Node> nodeLookup = new Dictionary<int, Node>();

    protected class Neighbour : IComparable<Neighbour>
    {
        public Node Node { get; private set; }
        public int Weight { get; private set; }

        public Neighbour(Node n, int w)
        {
            Node = n;
            Weight = w;
        }

        public int CompareTo(Neighbour other)
        {
            if (Weight < other.Weight) return -1;
            else if (Weight > other.Weight) return 1;
            else return 0;
        }
    }

    protected class Node
    {
        public int ID { get; private set; }
        public List<Neighbour> adjacent = new List<Neighbour>();

        public Node(int id)
        {
            ID = id;
        }
    }

    public WeightedGraph()
    {
        bidirectional = true;
    }

    public WeightedGraph(bool bidirectional)
    {
        this.bidirectional = bidirectional;
    }

	// Returns a node from an id
	// If one doesn't exist, creates a new one
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

    public void AddEdge(int start, int destination, int weight)
    {
        Node s = GetNode(start);
        Node d = GetNode(destination);
		
        s.adjacent.Add(new Neighbour(d, weight));
        if (bidirectional)
            d.adjacent.Add(new Neighbour(s, weight));
    }
}