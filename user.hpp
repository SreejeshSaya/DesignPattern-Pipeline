#ifndef USER_H
#define USER_H

#include<vector>

class User{

    public:

    int id;
    float initial_balance;
    User(float balance){
    
        id = users.size();
        users.push_back(*this);
        initial_balance = balance;
    }

    static User Alice;
    static User Bob;
    static User Charlie;
    

private:
    static std::vector<User> users;
   
};


#endif