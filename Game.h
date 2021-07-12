//
// Created by Asami on 12/07/2021.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "Board.h"
#include <array>

class Game {
public:
   explicit Game();
   ~Game();
   void makeMove(int);
   void displayBoard();
   bool gameWon;

private:
    std::array<std::array<Board::gameValue,3>,3> getBoard();
    bool boardFull;
    bool lastValuePlayedWasX;
    bool isGameWon();
    Board gameBoard;
    unsigned int movesMade;

};


#endif //TICTACTOE_GAME_H
