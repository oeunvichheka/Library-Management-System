#include <iostream>
#include <string>
using namespace std;

// Class to represent an Account
class UserAccount {
private:
    string username;
    string password;
    bool isLoggedIn;

public:
    UserAccount(string username, string password) 
        : username(username), password(password), isLoggedIn(false) {}

    // Getter for username
    string getUsername() const {
        return username;
    }

    // Login function
    bool login(string inputUsername, string inputPassword) {
        if (inputUsername == username && inputPassword == password) {
            isLoggedIn = true;
            return true;
        }
        return false;
    }

    // Register function (used during account creation)
    static UserAccount* registerAccount(const string& username, const string& password) {
        return new UserAccount(username, password);
    }

    bool getLoginStatus() const {
        return isLoggedIn;
    }

    void logout() {
        isLoggedIn = false;
    }
};