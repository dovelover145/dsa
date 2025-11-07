#include <iostream>
#include <string>
#include "balrog.h"
#include "demon.h"
using namespace std;

namespace cs_creature {
    Balrog::Balrog() : Demon() {
    }

    Balrog::Balrog(int inStrength, int inHitpoints) : Demon(inStrength, inHitpoints) {
    }

    string Balrog::getSpecies() const {
        return "Balrog";
    }

    int Balrog::getDamage() const {
        int damage;
        int damage2;
        //cout << getSpecies();
        damage = Demon::getDamage();
        damage2 = (rand() % getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        return damage + damage2;
    }
}