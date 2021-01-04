// ------ Includes ------
#include "Board.hpp"
#include "Instructions.hpp"
#include <limits>
using namespace std;

/*
========================================================================
Main starts the program
========================================================================
*/
int main() {
    Instructions instruct;
    Board board;
    bool flag = true;

    while (flag) {
        instruct.startScreen();
        cout << "Enter option by number.... ";
        int start_option = 0;
        cin >> start_option;
        
        // If 1 is entered, play game
        if (start_option == 1) {
            while(true) {
                board.print_board();
                int number = 0;
                string player = "";
                if (board.alternate_turns() == 0) {
                    cout << "Player 1, enter where you want to place your piece (Number).... ";
                    player = "X";
                }
                else {
                    cout << "Player 2, enter where you want to place your piece (Number).... ";
                    player = "O";
                }
                cin >> number;
                board.add_piece(number);
                if (board.check_win(board.mBoard, player)) {
                    board.print_board();
                    if (board.alternate_turns() == 0) {
                        cout << "Player 2 wins!" << endl;
                    }
                    else {
                        cout << "Player 1 wins!" << endl;
                    }
                    cout << "Enter P to play again, anything else to quit.... ";
                    string res = "";
                    cin >> res;
                    if (res == "P") {
                        board.board_clear();
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        // If 2 is entered, print instructions
        else if (start_option == 2) {
            cout << endl;
            instruct.howToPlay();
            cout << endl;
            while (cin.get() != 'q') {
                cout << "Enter q to continue... ";
            }
        }
        // If 3 is entered, quit the program
        else if (start_option == 3) {
            flag = false;
        }
        else {
            cout << "Invalid Option. Try again using numbers 1-3" << endl;
        }
    }
}