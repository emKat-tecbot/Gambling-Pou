#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Game_id {
    string id;
public:
    Game_id(string i) : id(i) {}
    string get_id() { return id; }
};

class wallet {
    int Poubucks;
public:
    wallet() : Poubucks(5) {}
    void add_money(int amount) { Poubucks += amount; }
    void spend_money(int amount) {
        if (Poubucks >= amount) Poubucks -= amount;
        else cout << "Not enough money!" << endl;
    }
    int get_money() { return Poubucks; }
};

class Work {
    string job;
    int salary;
public:
    Work(string j, int s) : job(j), salary(s) {}
    virtual void do_work(wallet &w, string pou) {
        cout << pou << " is working as a " << job << "\nHe earns " << salary << " Poubucks!" << endl;
        w.add_money(salary);
    }
};

class Item {
    string name;
    int smile_boost;
public:
    Item(string n, int s) : name(n), smile_boost(s) {}
    string get_name() { return name; }
    void use_item(string pou) {
        cout << pou << " uses " << name << " and feels " << smile_boost << " times happier!" << endl;
    }
};

class Store {
    Item item;
    int price;
public:
    Store(Item i, int p) : item(i), price(p) {}
    void buy(wallet &w, string pou) {
        cout << pou << " is trying to buy " << item.get_name() << " for " << price << " Poubucks." << endl;
        w.spend_money(price);
    }
};

class Gamble {
    int bet_amount;
public:
    Gamble(int b) : bet_amount(b) {}
    void play(wallet &w, string pou) {
        cout << pou << " is gambling with a bet of " << bet_amount << " Poubucks." << endl;
        if (rand() % 2 == 0) {
            cout << pou << " wins and earns " << bet_amount << " Poubucks!" << endl;
            w.add_money(bet_amount);
        } else {
            cout << pou << " loses " << bet_amount << " Poubucks!" << endl;
            w.spend_money(bet_amount);
        }
    }
};

int main() {
    wallet w;
    Work job("Chef", 10);
    job.do_work(w, "Pou");
    cout << "Wallet: " << w.get_money() << " Poubucks" << endl;

    Item ball("Ball", 5);
    Store store(ball, 3);
    store.buy(w, "Pou");

    Gamble g(2);
    g.play(w, "Pou");
    cout << "Final wallet: " << w.get_money() << " Poubucks" << endl;
    return 0;
}