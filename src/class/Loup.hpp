#ifndef _LOUP_H_
#define _LOUP_H_

#include "Animal.hpp"

class Loup : public Animal
{

    private:

    public:
        void setAttaque();

        void deplace(int maxX, int maxY);
};

#endif;