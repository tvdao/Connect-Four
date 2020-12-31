// ------ Includes ------
#include "Board.hpp"
using namespace std;

/*
 * Initializes a board object, creating an empty board
 */
Board::Board() {
    string top_label[] = { "1", "2", "3", "4", "5", "6", "7"};
    turn = 0;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        vector<string> row;
        for (int j = 0; j < BOARD_WIDTH; j++) {
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
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
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
    if (turn%2 == 0) { 
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
    for (int i = BOARD_HEIGHT-1; i > 0; i--) {
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

/* Getter method for turn
 * @return the variable turn
 */
int Board::get_turn() {
    return turn;
}

/*
 * Helper method to check horizontal win
 * @param vert: Vertical index
 * @param hor: Horizontal index 
 */
bool Board::check_horizontal(int vert, int hor) {
    string curr = mBoard[vert][hor];
    if (curr == "-") {
        return false;
    }
    int count = 1;
    int index = hor+1;
    while (count <= 4) {
        if (curr == mBoard[vert][index]) {
            count++;
            index++;
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
 */
bool Board::check_vertical(int vert, int hor) {
    string curr = mBoard[vert][hor];
    if (curr == "-") {
        return false;
    }
    int count = 1;
    int index = vert-1;
    while (count <= 4) {
        if (curr == mBoard[index][hor]) {
            count++;
            index--;
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
 * Helper method to check diagonal win
 * @param vert: Vertical index
 * @param hor: Horizontal index 
 */
bool Board::check_diagonal(int vert, int hor) {
    string curr = mBoard[vert][hor];
    if (curr == "-") {
        return false;
    }
    int count = 0;
    int left_dia_count = 0;
    int right_dia_count = 0;
    if (hor == 4) {
        for (int i = 0; i < 4; i++) {
            if (mBoard[vert][hor] == curr) {
                right_dia_count++;
                vert--;
                hor++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (mBoard[vert][hor] == curr) {
                left_dia_count++;
                vert--;
                hor--;
            }
            else {
                break;
            }
        }
    }
    else if (hor < 4) {
        for (int i = 0; i < 4; i++) {
            if (mBoard[vert][hor] == curr) {
                count++;
                vert--;
                hor++;
            }
            else {
                break;
            }
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (mBoard[vert][hor] == curr) {
                count++;
                vert--;
                hor--;
            }
            else {
                break;
            }
        }
    }
    if (right_dia_count == 4 || left_dia_count == 4 || count == 4) {
        return true;
    }
    else {
        return false;
    }
}

/*
 * Checks if any player won
 */
bool Board::check_win() {
    // Check horizontal
    for (int i = mBoard.size()-1; i > 0; i--) {
        for (int j = 1; j < mBoard[i].size(); j++) {
            if (j < 5) {
                if (check_horizontal(i, j)) {
                    return true;
                }   
            }
            if (i-3 > 0) {
                if (check_vertical(i, j)) {
                    return true;
                }
            }
            if (i >= 4) {
                if (check_diagonal(i, j)) {
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
    for (int i = 1; i < mBoard.size(); i++) {
        for (int j = 1; j < mBoard[i].size(); j++) {
            mBoard[i][j] = "-";
        }
    }
}