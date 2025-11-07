#include <iostream>
#include <string>
#include "cyberdemon.h"
#include "demon.h"
using namespace std;

namespace cs_creature {
    Cyberdemon::Cyberdemon() : Demon() {
    }

    Cyberdemon::Cyberdemon(int inStrength, int inHitpoints) : Demon(inStrength, inHitpoints) {
    }

    string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }

    /*
    int Cyberdemon::getDamage() const {
        int damage;
        // cout << getSpecies();
        damage = Demon::getDamage();
        return damage;
    }
    */
}
