// ------ Includes ------
#include "Computer.hpp"
using namespace std;

/*
 * Initializes a computer object
 */
Computer::Computer() {
    human_player = "O";
    ai_player = "X";
}

/*
 * Returns a vector of the indexes of empty spots on the board
 * @param board: The current state of the board
 */
 vector<int> empty_indexes(vector<vector<string>> board) {
     vector<string> empty;
     for (int i = 0; i < empty.size(); i++) {
         if (board[1][i] == "-") {
             empty[i] = i;
         }
     }
 }