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