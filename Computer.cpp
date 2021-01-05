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
    return 0;
}

/*
 * Helper method for lines_of_score, returns row score
 */
int horizontal_score(vector<vector<string>> board, string player, int column, int row) {
    int count = 0;
    int total = 0;
    int incr_point_col = column;
    int dec_point_col = column;
    for (int i = 0; i < FOUR; i++) {
        dec_point_col--;
        incr_point_col++;
        if (incr_point_col < SEVEN) {
            if (board[row][incr_point_col] == player) {
                count++;
            }
        }
        if (dec_point_col > -1) {
            if (board[row][dec_point_col] == player) {
                count++;
            }
        }
    }
    if (count == 2) {
        total = total + 3;
    }
    else if (count == 1) {
        total = total + 2;
    }
    else {}
    return total;
}

/*
 * Helper method for lines_of_score, returns column score
 */
int vertical_score(vector<vector<string>> board, string player, int column, int row) {
    int count = 0;
    int total = 0;
    int incr_point_vert = row;
    int dec_point_vert = row;
    for (int i = 0; i < FOUR; i++) {
        dec_point_vert--;
        incr_point_vert++;
        if (dec_point_vert > 0) {
            if (board[dec_point_vert][column] == player) {
                count++;
            }
        }
        if (incr_point_vert < SEVEN) {
            if (board[incr_point_vert][column] == player) {
                count++;
            }
        }
    }
    if (count == 2) {
        total = total + 3;
    }
    else if (count == 1) {
        total = total + 2;
    }
    else {}
    return total;
}

/*
 * Helper method for lines_of_score, returns diagonal score
 */
int diagonal_score(vector<vector<string>> board, string player, int column, int row) {
    int count = 0;
    int total = 0;
    int incr_point_vert = row;
    int dec_point_vert = row;
    for (int i = 0; i < FOUR; i++) {
        
    }
    for (int i = 0; i < FOUR; i++) {
        dec_point_vert--;
        incr_point_vert++;
        if (dec_point_vert > 0) {
            if (board[dec_point_vert][column] == player) {
                count++;
            }
        }
        if (incr_point_vert < SEVEN) {
            if (board[incr_point_vert][column] == player) {
                count++;
            }
        }
    }
    if (count == 2) {
        total = total + 3;
    }
    else if (count == 1) {
        total = total + 2;
    }
    else {}
    return total;
}

/*
 * Returns +2 or +3 if there is a line of two or three pieces
 * @param board: The current state of the bard;
 * @param player: The current player;
 * @param column: The column where the piece was added
 * @param row: The row where the piece was added
 * @return +2 if there is a line of two pieces
 */
int Computer::lines_of_score(vector<vector<string>> board, string player, int column, int row) {
    int total = 0;

    total += horizontal_score(board, player, column, row);
    total += vertical_score(board, player, column, row);
    
    return total;
}

 /*
 * Checks win for the player
 * @param board: The current state of the board
 * @param player: The current player
 * @param column: The column where the piece was added
 * @param row: The row where the piece was added
 * @return: true if there is a win, false if not
 */ 
bool Computer::winning(vector<vector<string>> board, string player) {
    return board_obj.check_win(board, player);
}