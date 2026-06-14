#include "Slot_machine.h"
#include "Pouxception.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Slot_Machine : public Minigame {
private:
    string name;
    std::vector<std::string> symbols;

public:
    Slot_Machine():name("Slot Machine"), symbols({"🜼","⟡","<3","✮","₍^. .^₎⟆"}){srand(time(0));};
    string spin(){return symbols[rand()% symbols.size()];}; // spin 3 times for the 3 simbols
    int play(int bet) override {
        string spin1 = spin();
        string spin2 = spin();
        string spin3 = spin();
        cout << "You spin..." << endl;
        cout << "[ " << spin1 << " | " << spin2 << " | " << spin3 << " ]";
        if(spin1 == spin2 && spin2 == spin3) // player wins
            if(spin1 == "⟡") // jackpot
                cout << "JACKPOT!!\n You won " << bet * 10 << endl;
                return bet * 10;
            cout << "Congratts!\n You won " << bet * 5 << endl; // not jackpot
        cout << "Sorry you lost!\n Better luck next time\n";
        return -bet; // looses
    };
    void Rules() override{
        cout << "SLOR MACHINE RULES\n 1.Three matching symbols = 5x your bet\n 2.Three diamonds = 10x your bet\n 3.No match = lose your bet\n Symbols: 🜼 ⟡ <3 ✮ ₍^. .^₎⟆\n";
    };
    string getName(){return name;};
};