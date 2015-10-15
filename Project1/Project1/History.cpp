#include "History.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols): m_nRows(nRows), m_nCols(nCols)
{
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            map[i][j] = '.';
}

bool History::record(int r, int c)
{
    if (r<1 || c<1 || r>MAXROWS || c>MAXCOLS)
        return false;
    r--; c--;
    switch (map[r][c]) {
        case '.':
            map[r][c] = 'A';
            break;
        case 'Z':
            break;
        default:
            map[r][c]++;
            break;
    }
    return true;
}

void History::display() const
{
    clearScreen();
    for (int i = 0; i < m_nRows; i++)
    {
        for (int j = 0; j < m_nCols; j++)
            cout << map[i][j];
        cout << endl;
    }
}