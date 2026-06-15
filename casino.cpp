#include "Casino.h"
#include "Slot_Machine.h"
#include "pou.h"
#include "high_or_lowMG.h"
#include "Pouxception.h"
#include <iostream>

Casino::Casino(Pou* pou) : pou(pou) {
    games.push_back(std::make_unique<Slot_Machine>());
    games.push_back(std::make_unique<High_or_Low>());
}

void Casino::showGames() const {
    std::cout << "=== CASINO GAMES ===\n";
    for (int i = 0; i < (int)games.size(); i++) {
        std::cout << i + 1 << ". " << games[i]->getName() << "\n";
    }
}

int Casino::playGame(int index, int bet) {
    if (index < 0 || index >= (int)games.size())
        throw Pouxception("We dont have that game!");

    pou->update_addiction(10);
    int result = games[index]->play(bet);

    if (result > 0) {
        pou->update_happy(15);
        pou->update_addiction(10);
        std::cout << "You won $" << result << "!\n";
    } else {
        pou->update_happy(-15);
        pou->update_addiction(5);
        std::cout << "You lost $" << result << "!\n";
    }
    return result;
}