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
bool Computer::is_moves_left(vector<vector<string>> board) {
    for (int i = 1; i < board.size(); i++) {
        if (board[1][i] == "-") {
            return true;
        }
    }
    return false;
}

/*
 * Returns a value based on "best move"
 * @param board: The current state of the board
 * @param player: The current player
 * @param column: The column where the piece was added
 * @param row: The row where the piece was added
 * @return: a value based on the "best move"
 */
int Computer::evaluate(vector<vector<string>> board, string player, int column, int row) {
    
}

/*
 * Returns +2 if there is a line of two pieces
 * @param board: The current state of the bard;
 * @param player: The current player;
 * @param column: The column where the piece was added
 * @param row: The row where the piece was added
 * @return +2 if there is a line of two pieces
 */
int lines_of_2_score(vector<vector<string>> board, string player, int column, int row) {
    int count = 0;
    if (player == human_player) {
        
    } 
    else {

    }
}

 /*
 * Checks win for the player
 * @param board: The current state of the board
 * @param player: The current player
 * @param column: The column where the piece was added
 * @param row: The row where the piece was added
 * @return: true if there is a win, false if not
 */ 
bool Computer::winning(vector<vector<string>> board, string player, int column, int row) {
    return board_obj.check_win(board, player);
}