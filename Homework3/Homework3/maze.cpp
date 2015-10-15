#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const short dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec) return true;
    maze[sr][sc] = 'X';
    for (int i = 0; i < 4; i++)
        if (maze[sr+dx[i]][sc+dy[i]] == '.' && pathExists(maze, nRows, nCols, sr+dx[i], sc+dy[i], er, ec))
            return true;
    return false;
}
