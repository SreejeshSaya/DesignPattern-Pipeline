#ifndef USER_H
#define USER_H

#include<vector>
#include<unordered_map>

class User {
private:
    float balance;
    unsigned int id;
    std::string username;

public:
    User(std::string, float);
    void displayInfo();

    static User Alice;
    static User Bob;
    static User Charlie;
    static std::vector<User> users_;

    static float getBalance(unsigned int);
    static void updateBalance(unsigned int, float);
    static User* getUser(unsigned int);
};


#endif