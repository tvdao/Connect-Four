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
    bool flag = true;
    while (flag) {
        instruct.startScreen();
        cout << "Enter option by number.... ";
        int start_option = 0;
        cin >> start_option;
        // If 1 is entered, play game
        if (start_option == 1) {

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