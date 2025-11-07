#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creature {
    class Demon : public Creature {
        public:
            Demon();
            Demon(int inStrength, int inHitpoints);
            std::string getSpecies() const;
            int getDamage() const;
    };
}

#endif
