#include "Slot_machine.h"
#include "Pouxception.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

Slot_Machine::Slot_Machine()
    : Minigame("Slot Machine"),
      symbols({"*","<>","<3","#","+_+"}) {
    srand(time(0));
}

std::string Slot_Machine::spin() {
    return symbols[rand() % symbols.size()];
}

int Slot_Machine::play(int bet) {
    std::string s1 = spin();
    std::string s2 = spin();
    std::string s3 = spin();

    std::cout << "You spin...\n";
    std::cout << "[ " << s1 << " | " << s2 << " | " << s3 << " ]\n";

    if (s1 == s2 && s2 == s3) {
        if (s1 == "<>") {
            std::cout << "JACKPOT!! You won $" << bet * 10 << "\n";
            return bet * 10;
        }
        std::cout << "Triple match! You won $" << bet * 5 << "\n";
        return bet * 5;
    }

    if (s1 == s2 || s2 == s3 || s1 == s3) {
        std::cout << "Two match! You won $" << bet * 2 << "\n";
        return bet * 2;
    }

    std::cout << "Sorry you lost $" << bet << "!\n";
    return -bet;
}

void Slot_Machine::Rules(){
    std::cout << "=== SLOT MACHINE RULES ===\n"
              << "1. Three matching symbols = 5x your bet\n"
              << "2. Three stars (⟡)        = 10x your bet\n"
              << "3. Two matching symbols   = 2x your bet\n"
              << "4. No match               = lose your bet\n"
              << "Symbols: 🜼 ⟡ <3 ✮ ₍^. .^₎⟆\n";
};