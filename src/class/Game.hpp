#ifndef _GAME_H_
#define _GAME_H_

// ================================================================================
// Includes
// ================================================================================
#include <vector>
#include <iostream>
#include "Animal.hpp"
using namespace std;

// ================================================================================
// Define
// ================================================================================
#define maxX 10
#define maxY 10

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

// ================================================================================
// Class def
// ================================================================================
class Game
{

private:
    vector<vector<Animal *>> board;

public:
    /**
     * @brief Construct a new Game object
     * Initialize Game by default
     */
    Game();

    /**
     * @brief Destroy the Game object
     */
    ~Game();

    /**
     * @brief Check if the Game is empty
     *
     * @return true
     * @return false
     */
    bool isEmpty();

    /**
     * @brief Displays the board in a terminal
     * 
     */
    void printBoardGame();
};

#endif