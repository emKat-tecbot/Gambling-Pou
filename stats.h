#ifndef STATS_H
#define STATS_H
#include <string>
using namespace std;

class Stats {
    private:
        int happy; //goes from 0 to 100, if it reaches 0, pou dies, affected by gambling
        int hunger; //goes from 0 to 100, if it reaches 100, pou dies
        int energy; //goes from 0 to 100, if it reaches 0, pou dies
        int hygiene; //goes from 0 to 100, if it reaches 0, pou dies
        int addiction; // goes from 0 to 100, if it reaches 100, pou refuses to work and player is forced to keep gambling
        string mood; // [HAPPY, HUNGRY, TIRED, DIRTY, ADDICTED, SAD]

    public:
        Stats();
        void barrier(int value)const; // ensures that stats dont go over 100 or under 0
        int getHappy();
        int getHunger();
        int getEnergy();
        int getHygiene();
        int getAddiction();
        string getMood();
        void setHappy(int happy);
        void setHunger(int hunger);
        void setEnergy(int energy);
        void setHygiene(int hygiene);
        void setAddiction(int addiction);  
};

#endif // STATS_H