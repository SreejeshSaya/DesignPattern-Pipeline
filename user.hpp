#ifndef USER_H
#define USER_H

#include<vector>
#include<unordered_map>

class User {
public:
    int id;
    float balance;

    User(float balance);

    static User Alice;
    static User Bob;
    static User Charlie;
    static std::vector<User> users_;

    static float getBalance(unsigned int);
    static void updateBalance(unsigned int, float);
};


#endif