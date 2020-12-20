// ------ Includes ------
#include "Board.hpp"
using namespace std;

/*
 * Initializes a board object, creating an empty board
 */
Board::Board() {
    string top_label[] = { "1", "2", "3", "4", "5", "6", "7"};
    string side_label[] = { "A", "B", "C", "D", "E", "F"};

    for (int i = 0; i < 8; i++) {
        vector<string> row;
        for (int j = 0; j < 7; j++) {
            // Writes in top label
            if ((i == 0) && (j > 0)) {
                row[j] = top_label[j-1];
                row.push_back(top_label[j-1]);
            }
            // Writes in side label
            else if ((i > 0) && (j == 0)) {
                // row[i] = side_label[i-1];
                row.push_back(side_label[i-1]);
            }
            // Writes in empty cells
            else {
                if ((i == 0) && (j == 0)) {
                    // row[0] = " ";
                    row.push_back(" ");
                }
                else {
                    // row[j] = "-";
                    row.push_back("-");
                }
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
 * @param letter: The vertical position of piece placement
 * @param number: The horizontal position of piece placement
 */
void Board::add_piece(string letter, int number) {
    int player = alternate_turns();
    string piece;
    // Assign the piece based off of alternate_turns
    if (player == 0) {
        piece = "X";
    }
    else {
        piece = "O";
    }
    for (int i = 0; i < mBoard.size(); i++) {
        // If letter matches the current letter on the side
        if (mBoard[i][0] == letter) {
            // If spot is empty
            if (mBoard[i][number] == "-") {
                mBoard[i][number] = piece;
                turn++;
            }
            // If spot is filled already
            else {
                cout << "Piece is already there. Try Again in an empty spot" << endl;
            }
        }
    }
}

/* Getter method for turn
 * @return the variable turn
 */
int get_turn() {
    return turn;
}
