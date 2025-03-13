#ifndef _PIERRE_H_
#define _PIERRE_H_

#include "Animal.hpp"

#define NAME_PIERRE "Pierre"

class Pierre : public Animal
{

    private:

    public:
        Pierre(int x, int y);
        Pierre(int x, int y, int a, int b);
        ~Pierre();
        void setAttaque();

        void deplace(int x, int y);
};

#endif