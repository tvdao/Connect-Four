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
    /*
     * Initializes a board object, creating an empty board
     */
    Board();

    /*
     * Prints current state of Board
     */
    void print_board();


};
#endif