//
// Created by Asami on 12/07/2021.
//

#include "Game.h"
#include <iostream>
#include <stdexcept>
#include <set>

using namespace std;

Game::Game(Board &board) {
    gameBoard = board;
    lastValuePlayedWasX = false;
    boardFull = false;
    gameWon = false;
    movesMade = 0;
}

Game::~Game() {
    cout << "Tearing down Game" << endl;
}

void Game::makeMove(int gridPosition) {
    if (gameWon) {
        throw logic_error("Game has already been won ...");
    }
    if (gridPosition < 1 || gridPosition > 9) {
        throw invalid_argument("grid position must be between 1 and 9");
    }
    if (boardFull) {
        throw logic_error("Game board is full and moves can no longer be made");
    }

    int zeroIndexedPosition = gridPosition - 1;
    int row = zeroIndexedPosition / 3;
    int column = zeroIndexedPosition % 3;

    array<array<Board::gameValue, 3>, 3> &gameArray = Game::getBoard();
    if (gameArray.at(row).at(column) != Board::EMPTY) {
        throw logic_error("board at that position is already occupied");
    }

    if (lastValuePlayedWasX) {
        gameArray.at(row).at(column) = Board::O;
        lastValuePlayedWasX = false;
    } else {
        gameArray.at(row).at(column) = Board::X;
        lastValuePlayedWasX = true;
    }
    gameWon = isGameWon();
}

void Game::displayBoard() {
    array<array<Board::gameValue, 3>, 3> &gameArray = Game::getBoard();
    for (size_t row = 0; row < gameArray.size(); row++) {
        for (size_t column = 0; column < gameArray.at(row).size(); column++) {
            cout << gameArray.at(row).at(column) << " ";
        }
        cout << endl;
    }
}

bool Game::isGameWon() {
    array<array<Board::gameValue, 3>, 3> &gameArray = Game::getBoard();
    for (int row = 0; row < gameArray.size(); ++row) {
        set<Board::gameValue> rowValues;
        for (int column = 0; column < gameArray.at(row).at(column); column++) {
            rowValues.insert(gameArray[row][column]);
        }
        bool doesNotContainEmpty = rowValues.count(Board::EMPTY) == 0;
        bool hasSameValues = rowValues.size() == 1;
        if (doesNotContainEmpty && hasSameValues) {
            cout << "row win" <<endl;
            return true;
        }
    }

    for (int column = 0; column < gameArray.size(); ++column) {
        set<Board::gameValue> columnValues;
        for (int row = 0; row < gameArray.size(); ++row) {
            columnValues.insert(gameArray[row][column]);
        }
        bool doesNotContainEmpty = columnValues.count(Board::EMPTY) == 0;
        bool hasSameValues = columnValues.size() == 1;
        if (doesNotContainEmpty && hasSameValues) {
            cout << "column win" <<endl;
            return true;
        }
    }
    set<Board::gameValue> leftDiagonalValues;
    for (int i = 0; i < gameArray.size(); i++) {
        int row = i;
        int column = i;
        leftDiagonalValues.insert(gameArray[row][column]);
    }
    bool doesNotContainEmpty = leftDiagonalValues.count(Board::EMPTY) == 0;
    bool hasSameValues = leftDiagonalValues.size() == 1;
    if (doesNotContainEmpty && hasSameValues) {
        cout << "left diag win" <<endl;
        return true;
    }
    set<Board::gameValue> rightDiagonalValues;
    for (int row = 2, column = 1; row >= 0 && column < gameArray.size(); row--, column++) {
        rightDiagonalValues.insert(gameArray.at(row).at(column));
    }
    doesNotContainEmpty = rightDiagonalValues.count(Board::EMPTY) == 0;
    hasSameValues = rightDiagonalValues.size() == 1;
    if (doesNotContainEmpty && hasSameValues) {
        cout << "right diag win" <<endl;
        return true;
    }
    return false;
}

array<std::array<Board::gameValue, 3>, 3> &Game::getBoard() {
    array<std::array<Board::gameValue, 3>, 3> &gameBoardArrayRef = gameBoard.getGameArray();
    return gameBoardArrayRef;
}