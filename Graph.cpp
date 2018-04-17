#include <iostream>
#include <map>
#include <vector>

class Node
{
public:
    std::vector<Node*> adjacent;
    Node(int id): ID(id) {}
private:
    int ID;
};

class Graph
{
public:
    void addEdge(int start, int destination)
    {
        Node* s = getNode(start);
        Node* d = getNode(destination);
        s->adjacent.push_back(d);
    }
    Graph(bool bidirect):bidirectional(bidirect){}
private:
    typedef std::map<int, Node*> inmap;
    inmap nodeLookup;
    bool bidirectional;
    Node* getNode(int id)
    {
        inmap::iterator it = nodeLookup.find(id);
        if (it != nodeLookup.end())
            return it->second;
        else
        {
            Node newNode(id);
            return nodeLookup[id] = &newNode;
        }
    }
};
