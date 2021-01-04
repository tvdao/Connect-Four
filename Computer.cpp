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
 * @return: a vector on indexes
 */
 vector<int> empty_indexes(vector<vector<string>> board) {
     vector<string> empty;
     for (int i = 0; i < empty.size(); i++) {
         // if top row has "-", then there is an empty spot in that column
         if (board[1][i] == "-") {
             empty.push_back(i);
         }
         // '10' represents not empty
         else {
             empty.push_back(TEN);
         }
     }
 }