//
// Created by Asami on 12/07/2021.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include <string>
#include <array>

class Board {
public:
    explicit Board();
    ~Board();
    void displayBoard();
    enum gameValue {X=1, O=0, EMPTY=2};
    std::array<std::array<gameValue, 3>,3>& getGameArray();
private:
    std::array<std::array<gameValue, 3>,3> gameArray;
};


#endif //TICTACTOE_BOARD_H
