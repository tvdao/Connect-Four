#ifndef COMPUTER_H
#define COMPUTER_H

// ------ Includes ------
#include "Board.hpp"
using namespace std;

// ------ Defines -------
#define TEN 10
#define FOUR 4
#define SIX 6
#define TWO 2
#define SEVEN 7
#define THREE 3

class Computer {
    private:

        string human_player;
        string ai_player;
        vector<vector<string>> curr_board;
        Board board_obj;
    public:

        /*
        * Initializes a computer object
        * @param board_object: A Board object to get the curr board state
        */
        Computer(Board board_object);

        /*
         * Returns true if moves remaining, else return false if none
         * @param board: The current state of the board
         * @return: a true if moves remaining, false if none
         */
        bool is_moves_left(vector<vector<string>> board);

        /*
         * Checks win for the player
         * @param board: The current state of the board
         * @param player: The current player
         * @return: true if there is a win, false if not
         */ 
        bool winning(vector<vector<string>> board, string player);

        /*
         * Returns a value based on "best move"
         * @param board: The current state of the board
         * @param player: The current player
         * @param column: The column where the piece was added
         * @param row: The row where the piece was added
         * @return: a value based on the "best move"
         */
        int evaluate(vector<vector<string>> board, string player, int column, int row);

        /*
        * Returns +2 or +3 if there is a line of two or three pieces
        * @param board: The current state of the bard;
        * @param player: The current player;
        * @param column: The column where the piece was added
        * @param row: The row where the piece was added
        * @return +2 or +3 if there is a line of two or three pieces
        */
        int lines_of_score(vector<vector<string>> board, string player, int column, int row);

        /*
         * Checks win for the player
         * @param board: The current state of the board
         * @param player: The current player
         * @param depth: How far the recursion will go
         * @return: The evaluation value 
         */ 
        int minimax(vector<vector<string>> board, int depth, string player);
        
        
};
#endif
