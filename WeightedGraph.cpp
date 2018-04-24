#include <iostream>
#include <Graph.cpp>
#include <set>

using namespace std;

class WeightedGraph : public Graph
{
private:
    typedef pair<Node*, int> pni;
    unordered_map<int, pni> nodeLookup;

protected:
    pni getNode(int id)
    {
        if (nodeLookup.find(id) != nodeLookup.end())
            return nodeLookup[id];
        else
        {
            // Create new and return
        }
    }

public:
    // Implement addEdge
};

int main()
{

}
