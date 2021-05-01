#ifndef USER_H
#define USER_H

#include<vector>
#include<unordered_map>

class User {
public:
    int id;
    float initial_balance;
   

    User(float balance) {
        

        id = users_.size();
        initial_balance = balance;
        users_.push_back(*this);

    }

    static User Alice;
    static User Bob;
    static User Charlie;
    static std::vector<User> users_;

   
   
};


#endif