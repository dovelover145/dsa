#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creature {
    class Elf : public Creature {
        public:
            Elf();
            Elf(int inStrength, int inHitpoints);
            std::string getSpecies() const;
            int getDamage() const;
    };
}

#endif
