#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > vvi;

vvi map;
int length, width;

bool fits(int x, int y)
{
    return (x < length && x >= 0) && (y < width && y >= 0);
}

void floodFill(int startX, int startY, int target, int replacement)
{
    if (!fits(startX, startY)) return;

    if (target == replacement) return;
    if (map[startX][startY] != target) return;

    map[startX][startY] = replacement;
    floodFill(startX+1, startY, target, replacement);
    floodFill(startX, startY+1, target, replacement);
    floodFill(startX-1, startY, target, replacement);
    floodFill(startX, startY-1, target, replacement);
}

int main ()
{
    length = 5, width = 5;

    map = vvi(length);
    for(int i = 0; i < width; i++)
        map.push_back(vector<int>(width));

    map[0][1] = 2;
    map[1][0] = 2;
    map[0][4] = 2;
    map[3][0] = 2;
    map[4][1] = 2;
    map[3][4] = 2;
    map[4][3] = 2;

    floodFill(2, 2, 0, 1);

    for (int row = 0; row < length; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int state = map[row][column];
            cout << ((state == 0) ? ' ' : (state == 1 ? '*' : 'H')); 
        }
        cout << '\n';
    }
}