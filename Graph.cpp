#include <iostream>
#include <map>
#include <set>

using namespace std;

class Node
{
    public:
        Node(int id);
        set<Node> adjacent;
    protected:
        int id;
};

Node::Node(int id)
{
    this->id = id;
}

class Graph
{
    public:
        Graph(bool bidirectional);
        void addEdge(int start, int destination);
    private:
        bool bidirectional;
        map<int, Node> nodeLookup;
        Node getNode(int id);
};

Graph::Graph(bool bidirectional)
{
    this->bidirectional = bidirectional;
}

void Graph::getNode(int id)
{

}

void Graph::addEdge(int start, int destination)
{
    Node s = getNode(start);
    Node d = getNode(destination);
    s.adjacent.insert(d);
    if (bidirectional)
        d.adjacent.insert(s);
}

int main()
{

}
