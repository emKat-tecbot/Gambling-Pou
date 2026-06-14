#ifndef POU_H
#define POU_H
#include "stats.h"
#include <string>
using namespace std;


class Pou{
    private:
    Stats stats; // stats of pou 
    string name;

    public:
        bool can_work(); // returns false if addiction_level is high 
        // update stats but delegate that to the stats class
        void update_happy(int amount);
        void update_hunger(int amount);
        void update_energy(int amount);
        void update_addiction(int amount);
        // getter
        string getName();
        // checkers (each round game checks if player lost or won)
        bool isDead(); // checks if pou is dead
        bool Won(); // checks if player won the game


};

#endif //POU_H