#include "Game.hpp"

/**
 * @brief Construct a new Game object
 * Initialize Game by default
 */
Game::Game()
{
    this->board = vector<vector<Animal *>>(maxY, vector<Animal *>(maxX, NULL));
};

bool Game::isEmpty()
{
    for (vector<Animal *> vect : this->board)
    {
        for (Animal *animal : vect)
        {
            if (animal != NULL && animal->getVivant() == 1)
            {
                return true;
            }
        }
    }
    return false;
}

void Game::printBoardGame()
{

    for (int i = 0; i < maxY + 3; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (vector<Animal *> vect : this->board)
    {
        for (Animal *animal : vect)
        {
            cout << '| ' << animal->getName().at(0) << ' ';
        }
        cout << '|' << endl;
    }
    for (int i = 0; i < maxY + 3; i++)
    {
        cout << "-";
    }
}
