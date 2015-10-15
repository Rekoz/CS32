//
//  History.h
//  Project1
//
//  Created by Yunong Jiang on 1/10/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#ifndef Project1_History_h
#define Project1_History_h

#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    char map[MAXROWS][MAXCOLS];
    int m_nRows;
    int m_nCols;
};

#endif
