#include "player.h"
#include "pou.h"
#include "Pouxception.h"
#include <iostream>

Player::Player(std::string id, int money, Pou* pou): id(id), money(money), pou(pou) {}

void Player::work() {
    if (!pou->can_work())
        throw Pouxception("Pou is too addicted to work!");
    money += 100;
    std::cout << "You worked! Money gained: $100\n";
}

void Player::care_for_pou() {
    if (money < 50)
        throw Pouxception("Not enough money to care for Pou!");
    money -= 50;
    pou->update_happy(20);
    pou->update_addiction(-10);
    std::cout << "You cared for Pou! Money left: $" << money << "\n";
}

void Player::gamble() {
    if (money < 50)
        throw Pouxception("You are too poor for the casino!");
    std::cout << "Let's gamble!...\n";
}

int Player::getMoney(){ return money; }
std::string Player::getId(){ return id; }

std::ostream& operator<<(std::ostream& os, const Player& p) {
    os << "Player: " << p.id
       << " | Money: $" << p.money;
    return os;
}

void Player::setMoney(int newM){money += newM;};