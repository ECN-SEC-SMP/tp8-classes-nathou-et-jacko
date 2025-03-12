#include "Game.hpp"

/**
 * @brief Construct a new Game object
 * Initialize Game by default
 */
Game::Game()
{
    this->board = vector<vector<Animal *>>(maxY, vector<Animal *>(maxX, NULL));
};

/**
 * @brief Check if the Game is empty
 *
 * @return true
 * @return false
 */
bool Game::isEmpty()
{
    for (vector<Animal *> vect : this->board)
    {
        for (Animal *animal : vect)
        {
            // if (animal != NULL && animal->getVivant() == 1)
            // {
            //     return true;
            // }
        }
    }
    return false;
}

Game::~Game()
{
}

/**
 * @brief Displays the board in a terminal
 *
 */
void Game::printBoardGame()
{

    for (int i = 0; i < maxY; i++)
    {
        cout << "----";
    }
    cout << "-" << endl;
    for (vector<Animal *> vect : this->board)
    {
        for (Animal *animal : vect)
        {
            cout << "| " << 'a' << ' ';
        }
        cout << "|" << endl;
        for (int i = 0; i < maxY; i++)
        {
            cout << "|---";
        }
        cout << "|" << endl;
    }
}
