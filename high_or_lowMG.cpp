#include "high_or_lowMG.h"
#include "Pouxception.h"
#include <iostream>
#include <cstdlib> // random numbers
#include <ctime>

class High_or_Low : public Minigame{
    private:
        int number; 
    public:
        High_or_Low(){
            number = rand() % 100 + 1; // random number between 1 and 100
        };
        bool play(int bet) override{
            int guess; // players guess
            cout << "Welcome to High or Low!\n GUESS A NUMBER BETWEE 1 AND 100 TO CONTINUE\n";
            cout << "You have 3 chances to guess the number \n";
            for (int i = 0; i < 3; i++){
                cout << "Guess: " << i+1 << endl;
                 cin >> guess;
                if (guess < 1 || guess > 100) // guard
                    throw Pouxception("INVALID GUESS\n GUESS A NUMBER BETWEE 1 AND 100 TO CONTINUE\n");
                if (guess == number){
                    cout << "You guessed the number!\n";
                    return true; // player wins
                } else if (guess < number)
                    cout << "HIGHER\n";
                else
                    cout << "LOWER\n";
            };
            cout << "You lost the bet! The number was: " << number << endl;
            return false; // player loses
        };
        void Rules() override{
            cout << "HIGH OR LOW RULES: \n 1. You have to guess a number between 1 and 100\n  2. You have 3 chances to guess the number\n 3. If you guess the number, you win the bet\n 4. If you dont guess the number, you lose the bet\n 5. After each guess, you will be told whether the number is higher or lower than your guess\n";
        };
};