// ------ Includes ------
#include "Computer.hpp"
using namespace std;

/*
 * Initializes a computer object
 * @param board_object: A Board object to get the curr board state
 */
Computer::Computer(Board::Board board_object) {
    human_player = "O";
    ai_player = "X";
    board = board_object.mBoard;
}

/*
 * Returns a vector of the indexes of empty spots on the board
 * @param board: The current state of the board
 * @return: a vector on indexes
 */
 vector<int> empty_indexes(vector<vector<string>> board) {
     vector<int> empty;
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
     return empty;
 }

 /*
 * Checks win for the player
 * @param board: The current state of the board
 * @param player: The current player
 * @return: true if there is a win, false if not
 */ 
bool winning(vector<vector<string>> board, string player) {

}