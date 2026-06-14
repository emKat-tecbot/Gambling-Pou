#ifndef HIGH_OR_LOW_H
#define HIGH_OR_LOW_H
#include "minigames.h"

class High_or_Low : public Minigame{
    private:
        string name;
        int number; //number player guesses 
    public:
        High_or_Low();
        int play(int bet) override; 
        void Rules() override;
        std::string getName(){return name;};
};
#endif // HIGH_OR_LOW_H