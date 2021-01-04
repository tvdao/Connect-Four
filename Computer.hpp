#ifndef COMPUTER_H
#define COMPUTER_H

// ------ Includes ------
#include "Board.hpp"
using namespace std;

// ------ Defines -------
#define TEN 10

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
         * @return: a value based on the "best move"
         */
        int evaluate(vector<vector<string>> board, string player, int column);

        /*
         * Returns +2 if there is a line of two pieces
         * @param board: The current state of the bard;
         * @param player: The current player;
         * @param column: The column where the piece was added
         * @return +2 if there is a line of two pieces
         */
        int lines_of_2_score(vector<vector<string>> board, string player, int column);

        /*
         * Returns +3 if there is a line of three pieces
         * @param board: The current state of the bard;
         * @param player: The current player;
         * @param column: The column where the piece was added
         * @return +3 if there is a line of three pieces
         */
        int lines_of_3_score(vector<vector<string>> board, string player, int column);

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
