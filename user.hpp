#ifndef USER_H
#define USER_H

#include<vector>

class User {
public:
    int id;
    float initial_balance;

    User(float balance) {
        id = users_.size();
        users_.push_back(*this);
        initial_balance = balance;
    }

    static User Alice;
    static User Bob;
    static User Charlie;
    static std::vector<User> users_;
   
};


#endif