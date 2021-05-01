#include <vector>
#include "user.hpp"

std::vector<User> User::users_;
User User::Alice((float)1000.00);
User User::Bob((float)1000.00);
User User::Charlie((float)1000.00);

User::User(float b):
    id(users_.size()), balance(b) {
    users_.push_back(*this); 
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