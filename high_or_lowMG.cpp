#include "high_or_lowMG.h"
#include "Pouxception.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

High_or_Low::High_or_Low()
    : Minigame("High or Low", 50) {
    srand(time(0));
    number = rand() % 100 + 1;
}

int High_or_Low::play(int bet) {
    int guess;
    std::cout << "Welcome to High or Low!\n";
    std::cout << "Guess a number between 1 and 100\n";
    std::cout << "You have 3 chances!\n";

    for (int i = 0; i < 3; i++) {
        std::cout << "Guess " << i + 1 << ": ";
        std::cin >> guess;

        if (guess < 1 || guess > 100)
            throw Pouxception("Invalid! Enter a number between 1 and 100");

        if (guess == number) {
            std::cout << "You guessed it! You won!\n";
            return bet;
        } else if (guess < number)
            std::cout << "HIGHER!\n";
        else
            std::cout << "LOWER!\n";
    }

    std::cout << "You lost! The number was: " << number << "\n";
    return -bet;
}

void High_or_Low::Rules(){
    std::cout << "=== HIGH OR LOW RULES ===\n"
              << "1. Guess a number between 1 and 100\n"
              << "2. You have 3 chances\n"
              << "3. Correct guess = win the bet\n"
              << "4. Wrong guess = lose the bet\n"
              << "5. After each guess you get a hint\n";
}