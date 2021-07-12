//
// Created by Asami on 12/07/2021.
//

#include "Board.h"
#include <string>
#include <iostream>

using namespace std;


Board::Board() {
    for (size_t row = 0; row < gameArray.size(); row++ ){
        for (size_t column = 0; column < gameArray.at(row).size(); column++) {
            gameArray.at(row).at(column) = EMPTY;
        }
    }
}
Board::~Board() {
    cout << "Tearing down board" << endl;
}
void Board::displayBoard() {
    for (size_t row = 0; row < gameArray.size(); row++ ){
        for (size_t column = 0; column < gameArray.at(row).size(); column++) {
            cout << gameArray.at(row).at(column)  << " ";
        }
        cout << endl;
    }
}
