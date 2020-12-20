#ifndef BOARD_H
#define BOARD_H

// ------ Includes ------
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ------ Defines -------
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 7

// ------------------------------------------------------------------------
//                                 Board
// ------------------------------------------------------------------------

class Board
{
private:
    vector< vector<string> > mBoard;   
public:

    Board();
    void printBoard();
};
#endif