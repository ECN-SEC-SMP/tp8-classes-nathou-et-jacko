#ifndef _LOUP_H_
#define _LOUP_H_

#include "Animal.hpp"

#define NAME_LOUP "Loup"

class Loup : public Animal
{

private:
public:
    Loup(int x, int y);
    Loup(int x, int y, int a, int b);
    void setAttaque();

    void deplace(int x, int y);
};

#endif