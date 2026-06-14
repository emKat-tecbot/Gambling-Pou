#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Pou; // Forward declaration of Pou class to avoid circular dependency, since Player has a pointer to Pou and Pou might have a pointer to Player.
class Player{
   private:
        string id;
        int money;
        Pou* pou; // Pou determines whether player works and player must take care of pou
    public:
        Player(string id, int money);
        ~Player();
        void work();
        virtual void care_for_pou();
        void gamble();
};

#endif //PLAYER_H
