#include "game_rounds.h"
#include "Pouxception.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameRound::GameRound() : turn(1) {
    std::string namePou;
    std::string namePlayer;

    std::cout << "Welcome to Pou my gambling addict!!\n";
    std::cout << "What would you like to name your Pou? ";
    std::cin >> namePou;
    std::cout << "Ok now what is your name? ";
    std::cin >> namePlayer;

    pou    = std::make_unique<Pou>();
    pou->setName(namePou);
    player = std::make_unique<Player>(namePlayer, 500, pou.get());
    casino = std::make_unique<Casino>(pou.get());

    srand(time(0));
    std::cout << ">> Hello " << namePlayer << ", my name is "
              << namePou << ". Nice to meet you!\n";
}

void GameRound::showMenu() const {
    std::cout << ">> What to do....?\n"
              << "1. Work\n"
              << "2. GAMBLE\n"
              << "3. Care for " << pou->getName() << "\n"
              << "4. Check stats\n";
}

void GameRound::showStatus() const {
    std::cout << *pou << "\n";
    std::cout << *player << "\n";
}

void GameRound::processChoice(int choice) {
    try {
        if (choice == 1) {
            player->work();
            std::cout << "You worked very hard!\n";
        } else if (choice == 2) {
            casino->showGames();
            std::cout << ">> Finally! what do you wanna play? ";
            int minigame;
            std::cin >> minigame;
            std::cout << ">> How much will you bet? ";
            int bet;
            std::cin >> bet;
            int result = casino->playGame(minigame - 1, bet);
            player->setMoney(result);
        } else if (choice == 3) {
            player->care_for_pou();
            std::cout << "Thankssss! love ya\n";
        } else if (choice == 4) {
            showStatus();
        } else {
            std::cout << ">> Oh i dont know about that one...\n";
        }
    } catch (const Pouxception& e) {
        std::cout << pou->getName() << " says: " << e.what() << "\n";
    }
}

void GameRound::start() {
    while (!pou->isDead() && !pou->Won()) {
        std::cout << "\n=== TURN " << turn << " ===\n";
        showStatus();

        if (stats->getAddiction() >= 61) {
            std::cout << ">> Hey buddy were going to the casino tonight!\n"
                      << "1. Give in\n"
                      << "2. Resist\n";
            int gamblerChoice;
            std::cin >> gamblerChoice;
            if (gamblerChoice == 1) {
                processChoice(2);
            } else {
                pou->update_happy(-20);
                std::cout << ">> How dare you...\n";
            }
        } else {
            showMenu();
            int choice;
            std::cin >> choice;
            processChoice(choice);
        }
        turn++;
    }

    if (pou->Won())
        std::cout << "\nYOU WIN! Pou is happy and addiction free!\n";
    else
        std::cout << "\nGAME OVER! Pou is gone.\n";
}