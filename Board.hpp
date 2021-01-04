#ifndef BOARD_H
#define BOARD_H

// ------ Includes ------
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ------ Defines -------
#define BOARD_WIDTH_HEIGHT 7
#define FOUR 4
#define THREE 3
#define TWO 2

// ------------------------------------------------------------------------
//                                 Board
// ------------------------------------------------------------------------

class Board
{
private:
    int turn;
public:
    vector< vector<string> > mBoard;  
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
     * @param board: Current state of board
     * @param player: Current player
     * return: True if win, false if not
     */
    bool check_win(vector<vector<string>> board, string player);

    /*
     * Alternate turns between Players 1 and 2
     * @return 0 if player 2, 1 if player 1
     */
    int alternate_turns();

    /*
     * Helper method to check horizontal win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     * @param board: Current state of board
     * @param player: Current player
     * return: True if win, false if not
     */
    bool check_horizontal(int vert, int hor, vector<vector<string>> board, string player);

    /*
     * Helper method to check vertical win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     * @param board: Current state of board
     * @param player: Current player
     * return: True if win, false if not
     */
    bool check_vertical(int vert, int hor, vector<vector<string>> board, string player);

    /*
     * Helper method to check diagonal win
     * @param vert: Vertical index
     * @param hor: Horizontal index 
     * @param board: Current state of board
     * @param player: Current player
     * return: True if win, false if not
     */
    bool check_diagonal(int vert, int hor, vector<vector<string>> board, string player);

    /*
     * Clears the board
     */
    void board_clear();
};
#endif