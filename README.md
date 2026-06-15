## Gambler Pou Simulator

A C++ text-based game where you care for a virtual pet named Pou while managing their gambling addiction. Modern virtual pet games lack realistic consecuences for poor descision making and players can neglect withough meaningfull feedback. This simulator creates a negative feedback loop where gambling affects a pets addiction stats, which then influences gamplay options. The pet can die from neglect or recover through proper care, creating meaningful consequences for every player choice. 

# Build command

g++ -std=c++14 -Wall -o PouGame.exe main.cpp Game_Rounds.cpp Casino.cpp High_or_LowMG.cpp Player.cpp Pou.cpp Slot_Machine.cpp Stats.cpp

-std=c++14 (Uses C++14 standard)

-Wall (Enables all compiler warnings)

-o PouGame.exe (Output executable name)

# Running instructions
Windows (MSYS2 UCRT64): ./PouGame.exe

Windows (Command Prompt):PouGame.exe

# Expected First-Time Setup:
Welcome to Pou my gambling addict!!5.
What would you like to name your Pou? Lucky
Ok now what is your name? Emma
>> Hello Emma, my name is Lucky. Nice to meet you!

# Tour
Polymorphism and abstract base clases
In minigames.h, Slot_machine.cpp and high_or_low.cpp (allow casino to store a unique pointer called minigame that can call play withought knowing which game it is)

2. RAII and smart pointers
  In game_rounds.h (no manual delete is needed sicne memory is automatically freed when GameRound destructs)

3. Exception handling
  In Pousception.h (arrors are thrown withoiught crashing)

4. Encapsulation
  In stats.h and pou.h (prevent invalid stats by having stats in an interal between 0 and 100)

5. Operator overloading
  In pou.cpp and player.cpp (because we need a natural syntax for printing the stats of player and pou)

6. Ownership and Rule of 0

  Ownership map:
GameRound (OWNER)
    ├── unique_ptr<Pou> ─────────────► Pou (owned by GameRound)
    ├── unique_ptr<Player> ──────────► Player
    │       └── Pou* (non-owning) ────┘ (observes, doesn't own)
    └── unique_ptr<Casino> ──────────► Casino
            └── vector<unique_ptr<Minigame>>
                    ├── Slot_Machine (owned by vector)
                    └── High_or_Low (owned by vector)


  Rule of 0 used in stats class, pouxception class and minigame class because either all members self manage, there are only string members wich auto destruct or because there are no dynamic reasources and so the default destructer is fine)

7. Virtual destructor
  In minigame class (we must ensure that derived classes destructors are called properly when deleting through a base pointer)

8. Class relationships
  Composition in Pou with stats (stasts are integral to pou, no other class needs acces to stats and withought pou the stats cant exist)

  Agregation in Player with pou(the player can exist withought pou and player could never call delete pou)

  Dependency in casino with int playGame(int index, int bet) (each game rounf is independent of eachother so it dosent make sence that casino keep the value of bet safe in memory when it will always keep changing)

9. Inheritance
  In minigame with slot machine and high or low (because slot machine and high and low share a is a realshionship with minigame and name must be accesed by derivd classes)
