// ------ Includes ------
#include "Board.hpp"
using namespace std;

/*
 * Initializes a board object, creating an empty board
 */
Board::Board() {
    string top_label[] = { "1", "2", "3", "4", "5", "6", "7"};
    turn = 0;
    for (int i = 0; i < BOARD_WIDTH_HEIGHT; i++) {
        vector<string> row;
        for (int j = 0; j < BOARD_WIDTH_HEIGHT; j++) {
            // Writes in top label
            if (i == 0) {
                row.push_back(top_label[j]);
            }
            // Writes in empty cells
            else {
                // row[j] = "-";
                row.push_back("-");
            }
        }
        mBoard.push_back(row);
    }
}

/*
 * Prints current state of Board
 */
void Board::print_board() {
    cout << endl;
    for (int i = 0; i < BOARD_WIDTH_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH_HEIGHT; j++) {
            cout << mBoard[i][j] << "   ";
        }
        cout << endl;
        cout << endl;
    }
}
/*
 * Alternate turns between Players 1 and 2
 * @return 0 if player 2, 1 if player 1
 */
int Board::alternate_turns() {
    if (turn%TWO == 0) { 
        return 0;
    }
    else {
        return 1;
    }
 }

/*
 * Add player piece (either X or O) to board
 * @param number: The horizontal position of piece placement
 */
void Board::add_piece(int number) {
    int player = alternate_turns();
    string piece;
    // Assign the piece based off of alternate_turns
    if (player == 0) {
        piece = "X";
    }
    else {
        piece = "O";
    }
    // Checks for first available row to insert
    for (int i = BOARD_WIDTH_HEIGHT-1; i > 0; i--) {
        // If spot is empty
        if (mBoard[i][number-1] == "-") {
            mBoard[i][number-1] = piece;
            turn++;
            return;
        }
    }
    cout << "No available spot" << endl;
    return;
}

/*
 * Helper method to check horizontal win
 * @param vert: Vertical index
 * @param hor: Horizontal index
 * @param board: Current state of board
 * @param player: Current player
 * return: True if win, false if not 
 */
bool Board::check_horizontal(int vert, int hor, vector< vector<string> > board, string player) {
    string curr = player;
    // If "-", then there is no connect four
    if (board[vert][hor] == "-") {
        return false;
    }
    int count = 0;
    // Checks the horizontal for 4 in a row
    while (count < FOUR) {
        if (curr == board[vert][hor]) {
            count++;
            hor++;
        }
        else {
            break;
        }
    }
    if (count == 4) {
        return true;
    }
    else {
        return false;
    }
}

/*
 * Helper method to check vertical win
 * @param vert: Vertical index
 * @param hor: Horizontal index 
 * @param board: Current state of board
 * @param player: Current player
 * return: True if win, false if not
 */
bool Board::check_vertical(int vert, int hor, vector< vector<string> > board, string player) {
    string curr = player;
    // If "-", then there is no connect four
    if (board[vert][hor] == "-") {
        return false;
    }
    int count = 0;

    // Checks the vertical for 4 in a row
    while (count < FOUR) {
        if (curr == board[vert][hor]) {
            count++;
            vert--;
        }
        else {
            break;
        }
    }
    if (count == FOUR) {
        return true;
    }
    else {
        return false;
    }
}

/*
 * Helper method to check diagonal win
 * @param vert: Vertical index
 * @param hor: Horizontal index 
 * @param board: Current state of board
 * @param player: Current player
 * return: True if win, false if not
 */
bool Board::check_diagonal(int vert, int hor, vector< vector<string> > board, string player) {
    string curr = player;
    if (board[vert][hor] == "-") {
        return false;
    }
    int count = 0;
    int left_dia_count = 0;
    int right_dia_count = 0;
    // Only middle spot
    if (hor == THREE) {
        int right_vert = vert;
        int right_hor = hor;
        // Checks right diagonal
        for (int i = 0; i < FOUR; i++) {
            if (board[right_vert][right_hor] == curr) {
                right_dia_count++;
                right_vert--;
                right_hor++;
            }
            else {
                break;
            }
        }
        // Checks left diagonal
        for (int i = 0; i < FOUR; i++) {
            if (board[vert][hor] == curr) {
                left_dia_count++;
                vert--;
                hor--;
            }
            else {
                break;
            }
        }
    }
    // For vertical column indices 0, 1, 2
    else if (hor < THREE) {
        for (int i = 0; i < FOUR; i++) {
            if (board[vert][hor] == curr) {
                count++;
                vert--;
                hor++;
            }
            else {
                break;
            }
        }
    }
    // For vertical column indices 4, 5, 6
    else {
        for (int i = 0; i < FOUR; i++) {
            if (board[vert][hor] == curr) {
                count++;
                vert--;
                hor--;
            }
            else {
                break;
            }
        }
    }
    // Checks if the count is 4, which means there is a 4 in a row/vertical/diagonal
    if (right_dia_count == FOUR || left_dia_count == FOUR || count == FOUR) {
        return true;
    }
    else {
        return false;
    }
}

/*
 * Checks if any player won
 * @param board: Current state of board
 * @param player: Current player
 * return: True if win, false if not
 */
bool Board::check_win(vector<vector<string>> board, string player) {
    for (int i = BOARD_WIDTH_HEIGHT-1; i > 0; i--) {
        for (int j = 0; j < BOARD_WIDTH_HEIGHT; j++) {
            // Checks horizontal win
            if (j < FOUR) {
                if (check_horizontal(i, j, board, player)) {
                    return true;
                }   
            }
            // Checks vertical win
            if (i-THREE > 0) {
                if (check_vertical(i, j, board, player)) {
                    return true;
                }
            }
            // Checks diagonal win
            if (i > THREE) {
                if (check_diagonal(i, j, board, player)) {
                    return true;
                }
            }
        }
    }
    return false;
}

/*
 * Clears the board
 */
void Board::board_clear() {
    for (int i = BOARD_WIDTH_HEIGHT-1; i > 0; i--) {
        for (int j = 0; j < BOARD_WIDTH_HEIGHT; j++) {
            // Set each grid spot to "-"
            mBoard[i][j] = "-";
        }
    }
}