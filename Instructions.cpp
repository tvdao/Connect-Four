// ----- Includes -----
#include "Instructions.hpp"

/*
========================================================================
Prints the start screen
========================================================================
*/
void Instructions::startScreen() {
    cout << "-------- Welcome to Connect Four --------" << endl;
    cout << "1) Play" << endl;
    cout << "2) Instructions" << endl;
    cout << "3) Exit" << endl;
}

/*
========================================================================
Prints the rules and how to play in Connect Four
========================================================================
*/
void Instructions::howToPlay() {
    cout << "-------- Objective --------" << endl;
    cout << "   Be the first player to get four of your shape(O or X) in a row" << endl;
    cout << "horizontally, vertically, or diagonally" << endl;
    cout << "-------- How To Play --------" << endl;
    cout << "1) Players will alterenate turns after playing a piece." << endl;
    cout << "2) On your turn, type the coordinate (Letter, Number) where you" << endl;
    cout << "   want your piece to be." << endl;
    cout << "3) Play alternate until one player gets FOUR checkers of their shape" << endl;
    cout << "   in a row. The four in a row can be horizontal, vertical, or diagonal" << endl;
    cout << "-------- How To Win --------" << endl;
    cout << "   If you're the first player to get four in a row, you win the game!" << endl;
}
