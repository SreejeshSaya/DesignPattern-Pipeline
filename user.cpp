#include <vector>
#include "user.hpp"
#include <iostream>

std::vector<User> User::users_;
User User::Alice("Alice", (float)1000.00);
User User::Bob("Bob", (float)1000.00);
User User::Charlie("Charlie", (float)1000.00);

User::User(std::string name, float b):
    id(users_.size()), username(name), balance(b) {
    users_.push_back(*this); 
}

void User::displayInfo() {
    std::cout << "Name: " << username << "\tID: " << id  << "\tBalance: " << balance << std::endl;
    return;
}

float User::getBalance(unsigned int uid) {
    if(uid > users_.size())
        return 0;
    return users_[uid].balance;
}

void User::updateBalance(unsigned int uid, float bal) {
    if (uid < users_.size())
        users_[uid].balance = bal;
}

User* User::getUser(unsigned int uid) {
    if (uid >= users_.size())
        return nullptr;
    return &users_[uid];
}