#include <iostream>
#include <stdexcept>
#include "Game.h"

using namespace std;

int main() {
    Board board = Board();
    Game ticTacToe = Game(board);
    while (!ticTacToe.gameWon){
        try {
            int positionPlayed;
            cout << "Enter a position between 1 and 9 to make a move " << endl;
            cin >> positionPlayed;
            ticTacToe.makeMove(positionPlayed);
            ticTacToe.displayBoard();
        } catch (logic_error& error) {
            cout << error.what() <<endl;
        }

    }
    return 0;
}
