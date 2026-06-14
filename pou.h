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
        int update_happy(int amount);
        int update_hunger(int amount);
        int update_energy(int amount);
        int update_hygiene(int amount);
        int update_addiction(int amount);

        // getters
        string getName();
        

};

#endif //POU_H