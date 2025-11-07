#include <iostream>
#include <string>
#include <cstdlib>
#include "elf.h"
#include "creature.h"
using namespace std;

namespace cs_creature {
    Elf::Elf() : Creature() {
    }

    Elf::Elf(int inStrength, int inHitpoints) : Creature(inStrength, inHitpoints) {
    }

    string Elf::getSpecies() const {
        return "Elf";
    }

    int Elf::getDamage() const {
        int damage;
        damage = Creature::getDamage();
        // cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;
        }
        return damage;
    }
}
