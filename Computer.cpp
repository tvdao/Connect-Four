// ------ Includes ------
#include "Computer.hpp"
using namespace std;

/*
 * Initializes a computer object
 * @param board_object: A Board object to get the curr board state
 */
Computer::Computer(Board board_object) {
    human_player = "O";
    ai_player = "X";
    curr_board = board_object.mBoard;
    board_obj = board_object;
}

 /*
 * Returns true if moves remaining, else return false if none
 * @param board: The current state of the board
 * @return: a true if moves remaining, false if none
 */
bool is_moves_left(vector<vector<string>> board) {
    for (int i = 1; i < board.size(); i++) {
        if (board[1][i] == "-") {
            return true;
        }
    }
    return false;
}

 /*
 * Checks win for the player
 * @param board: The current state of the board
 * @param player: The current player
 * @return: true if there is a win, false if not
 */ 
bool winning(vector<vector<string>> board, string player) {
    return board_obj.check_win(board, player);
}