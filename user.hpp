#ifndef USER_H
#define USER_H

#include<vector>
#include<unordered_map>

class User {
private:
    float balance;
    std::string username;
    static std::vector<User> users_;

public:
    unsigned int id;
    User(std::string, float);
    void displayInfo();

    static User Alice;
    static User Bob;
    static User Charlie;

    static float getBalance(unsigned int);
    static void updateBalance(unsigned int, float);
    static User* getUser(unsigned int);
};


#endif