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
        Player(string id, int money, Pou* pou);
        ~Player();
        void work();
        virtual void care_for_pou();
        void gamble();
        int getMoney();
        string getId();
        void setMoney(int newM);
        friend ostream& operator <<(ostream& os, const Player&p); // to the lest of << cout(std ostream) so must be free function that can read private members
};

#endif //PLAYER_H
