#ifndef _OURS_H_
#define _OURS_H_

#include "Animal.hpp"

#define NAME_OURS "Ours"

class Ours : public Animal
{

private:
public:
    Ours(int x, int y);
    Ours(int x, int y, int a, int b);
    void setAttaque();

    void deplace(int x, int y);
};

#endif