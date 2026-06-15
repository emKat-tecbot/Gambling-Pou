#include "game_rounds.h"
#include "Pouxception.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class GameRound{
    unique_ptr<Pou> pou;
    unique_ptr<Player> player;
    unique_ptr<Casino> casino;
    unique_ptr<Stats> stats;
    int turn;
    public:
        GameRound():turn(1){
            string namePou;
            cout << "Welcome to Pou my gambling addict!!";
            cout << "What would you like to name your Pou?";
            cin >> namePou;
            string namePlayer;
            cout << "Ok now what is your name? ";
            cin >> namePlayer;

            // create pou
            pou = make_unique<Pou>(namePou);
            player = make_unique<Player>(namePlayer, 500,pou.get());
            casino = make_unique<Casino>(pou.get());
            srand(time(0));
            cout << ">> Hello " << namePlayer << ", my name is " << namePou << ". Nice to meet you!" << endl;
        };
        void showMenu() const{
            cout << ">> What to do....?\n" << "1. Work\n" << "2. GAMBLE\n" << "3. Care for " << pou->getName() << "\n" << "4. Check stats\n";
        };
        void showStats() const{
            cout << *pou << "\n"; // to redefine << operator
            cout << *player << "\n";
        };
        void processChoice(int choice){
            try{
                if (choice == 1){
                    player->work();
                    cout << "You worked very hard!\n";
                }else if (choice == 2){
                    casino->showGames();
                    cout << ">> Finally! what do you wanna play? ";
                    int minigame;
                    cin >> minigame;
                    cout << ">> How much will i bet? ";
                    int bet;
                    cin >> bet;
                    casino ->playGame(minigame -1, bet);
                }else if (choice == 3){
                    player->care_for_pou();
                    cout << "Thankssss! love ya";
                }else if(choice == 4){
                    showStats();
                }else{
                    cout << ">> Oh i dont know about that one...\n";
                }
            }
            catch(const Pouxception& e){
                cout << pou->getName() << " says: " << e.what() << "\n";
            }
        };
        void start(){// game
            while(!pou->isDead() && !pou->Won()){
                cout << "TURN " << turn << "\n";
                showStats();

                // pou when addiction is high
                if(stats->getAddiction() < 61){
                    cout << ">> Hey buddy were going to the casino tonight and youre gonna like it" << endl;
                    cout << "1. GAMBLE"
                         << "2. Give in" << endl;
                    int gamblerChoice;
                    if(gamblerChoice == 1){
                        processChoice(2);
                    } else {
                        pou->update_happy(-20);
                        cout << ">> How dare you...\n";
                    };
                } else {
                    showMenu();
                    int choice;
                    cin >> choice;
                    processChoice(choice);
                };
            };
        };
};