#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;

vvi graph;
int length, width;

// Check if values fit in the graph
bool fits(int x, int y)
{
    return (x < length && x >= 0) && (y < width && y >= 0);
}

// Target = the identifier which will be replaced
// Replacement = the identifier which will replace the target
void floodFillRecursive(int startX, int startY, int target, int replacement)
{
    if (!fits(startX, startY)) return;

    if (target == replacement) return;
    if (graph[startX][startY] != target) return;

    graph[startX][startY] = replacement;
    floodFillRecursive(startX+1, startY, target, replacement);
    floodFillRecursive(startX, startY+1, target, replacement);
    floodFillRecursive(startX-1, startY, target, replacement);
    floodFillRecursive(startX, startY-1, target, replacement);
}

void floodFillIterative(int startX, int startY, int target, int replacement)
{
    // Where pii.first represents the row and second represents the column
    queue<pii> Q;
    Q.push(pii(startX, startY));

    while(!Q.empty())
    {
        pii node = Q.front();
        Q.pop();

        if (!fits(node.first, node.second)) continue;
        if (target == replacement) continue;
        if (graph[node.first][node.second] != target) continue;

        graph[node.first][node.second] = replacement;
        Q.push(pii(node.first+1, node.second));
        Q.push(pii(node.first, node.second+1));
        Q.push(pii(node.first-1, node.second));
        Q.push(pii(node.first, node.second-1));
    }
}

/* Reached nodes: '*'
 / Obstacles: 'H'
 / Not reached nodes: ' '
 */
void printGraph()
{
    for (int row = 0; row < length; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int state = graph[row][column];
            cout << ((state == 0) ? ' ' : (state == 1 ? '*' : 'H'));
        }
        cout << '\n';
    }
}

int main ()
{
    length = 5, width = 5;

    graph = vvi(length);
    for(int i = 0; i < width; i++)
        graph[i] = vector<int>(width);

    // Add obstacles
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[0][4] = 2;
    graph[3][0] = 2;
    graph[4][1] = 2;
    graph[3][4] = 2;
    graph[4][3] = 2;

    floodFillIterative(2, 2, 0, 1);

    printGraph();
}
