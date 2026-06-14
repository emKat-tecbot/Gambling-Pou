#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player{
   private:
        string id;
        int money;
    public:
        Player(string id, int money);
        void work();
        void care_for_pou();
        void gamble();
};

#endif //PLAYER_H
