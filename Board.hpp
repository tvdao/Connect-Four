#ifndef BOARD_H
#define BOARD_H

// ------ Includes ------
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ------ Defines -------
#define BOARD_WIDTH 7
#define BOARD_HEIGHT 7

// ------------------------------------------------------------------------
//                                 Board
// ------------------------------------------------------------------------

class Board
{
private:

    vector< vector<string> > mBoard;   
    int turn;
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
     * @param number: The horizontal position of piece placement
     */
    void add_piece(int number);

    /*
     * Checks if any player won
     */
    bool check_win();

    /*
     * Alternate turns between Players 1 and 2
     * @return 0 if player 2, 1 if player 1
     */
    int alternate_turns();

    /* Getter method for turn
     * @return the variable turn
     */
    int get_turn();

    /*
     * Helper method to check horizontal win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     */
    bool check_horizontal(int vert, int hor);

    /*
     * Helper method to check vertical win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     */
    bool check_vertical(int vert, int hor);

    /*
     * Helper method to check diagonal win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     */
    bool check_diagonal(int vert, int hor);

    /*
     * Clears the board
     */
    void board_clear();
};
#endif