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
         * Checks win for the player
         * @param board: The current state of the board
         * @param player: The current player
         * @return: The evaluation value 
         */ 
        int minimax(vector<vector<string>> board, string player);
        
        
};
#endif
