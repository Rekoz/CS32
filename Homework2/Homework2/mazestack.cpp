//
//  main.cpp
//  Homework2
//
//  Created by Yunong Jiang on 1/30/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

const short DX[4] = {-1, 0, 1, 0};
const short DY[4] = {0, 1, 0, -1};

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    stack<Coord> coordstack;
    coordstack.push(Coord(sr, sc));
    maze[sr][sc] = '#';
    int r, c, rr, cc;
    while (!coordstack.empty())
    {
        Coord a = coordstack.top();
        cerr << a.r() << ' ' << a.c() << endl;
        coordstack.pop();
        r = a.r(); c = a.c();
        if (r == er && c == ec)
            return true;
        for (short i = 0; i < 4; i++)
        {
            rr = r+DX[i]; cc = c+DY[i];
            if (rr >= 0 && rr < nRows && cc >=0 && cc < nCols && maze[rr][cc] == '.')
            {
                coordstack.push(Coord(rr, cc));
                maze[rr][cc] = '#';
            }
        }
    }
    return false;
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10, 10, 6, 4, 1, 1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
