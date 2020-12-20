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

    /*
     * Add player piece (either X or O) to board
     * @param letter: The vertical position of piece placement
     * @param number: The horizontal position of piece placement
     * @param player: Either player 1 or player 2
     */
    void add_board(string letter, int number, int player);

};
#endif