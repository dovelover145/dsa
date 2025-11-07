#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include <iostream>
#include <string>
#include "demon.h"

namespace cs_creature {
    class Cyberdemon : public Demon {
        public:
            Cyberdemon();
            Cyberdemon(int inStrength, int inHitpoints);
            std::string getSpecies() const;
            // int getDamage() const;
    };
}

#endif
