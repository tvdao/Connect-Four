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
    public:

        Computer();

        /*
         * Returns a vector of the indexes of empty spots on the board
         * @param board: The current state of the board
         * @return: a vector on indexes
         */
        vector<int> empty_indexes(vector<vector<string>> board);

        /*
         * Checks win for the player
         * @param board: The current state of the board
         * @param player: The current player
         */ 
        bool winning(vector<vector<string>> board, string player);

        /*
         * Checks win for the player
         * @param board: The current state of the board
         * @param player: The current player
         */ 
        
        
};
#endif
