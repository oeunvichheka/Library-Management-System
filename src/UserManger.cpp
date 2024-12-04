
#include <iostream>
#include <string>
#include "UserAccount.cpp"
#include "AddOnBook.cpp"
using namespace std;

class UserManager {
private:
    vector<UserAccount*> accounts;
    UserAccount* currentUser;
    AddOnBook* currentAddOnBook;

public:
    UserManager() : currentUser(nullptr), currentAddOnBook(new AddOnBook()) {}

    // Register a new user account
    void registerAccount(const string& username, const string& password) {
        UserAccount* newAccount = UserAccount::registerAccount(username, password);
        accounts.push_back(newAccount);
        cout << "Account created successfully for: " << username << endl;
    }

    // Login a user
    void login(const string& username, const string& password) {
        for (auto& account : accounts) {
            if (account->login(username, password)) {
                currentUser = account;
                cout << "Login successful for: " << username << endl;
                return;
            }
        }
        cout << "Login failed. Invalid credentials." << endl;
    }

    // Logout the current user
    void logout() {
        if (currentUser != nullptr) {
            currentUser->logout();
            cout << "Logged out successfully!" << endl;
            currentUser = nullptr;
        } else {
            cout << "No user is logged in." << endl;
        }
    }

    // Add an add-on to the book
    void addAddOnToBook(const string& addOn) {
        if (currentUser == nullptr) {
            cout << "Please login first to add an add-on." << endl;
            return;
        }
        currentAddOnBook->addAddOn(addOn);
    }

    // Remove an add-on from the book
    void removeAddOnFromBook(const string& addOn) {
        if (currentUser == nullptr) {
            cout << "Please login first to remove an add-on." << endl;
            return;
        }
        currentAddOnBook->removeAddOn(addOn);
    }

    // Show all current add-ons
    void showAddOns() {
        currentAddOnBook->showAddOns();
    }

    bool getLoginStatus() const {
        return currentUser != nullptr && currentUser->getLoginStatus();
    }

    ~UserManager() {
        // Clean up dynamically allocated memory for UserAccounts
        for (auto& account : accounts) {
            delete account;
        }
        delete currentAddOnBook;
    }
};

// Function to display the main menu
void showMenu() {
    cout << "\n====== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "1. Register Account\n";
    cout << "2. Login\n";
    cout << "3. Add Add-On\n";
    cout << "4. Remove Add-On\n";
    cout << "5. Show Add-Ons\n";
    cout << "6. Logout\n";
    cout << "7. Exit\n";
    cout << "Select an option (1-7): ";
}

int main() {
    UserManager userManager;
    int option;
    string username, password, addOn;
    
    while (true) {
        showMenu();
        cin >> option;
        cin.ignore(); // To clear the newline from the input buffer
        
        switch (option) {
            case 1: // Register Account
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                userManager.registerAccount(username, password);
                break;
                
            case 2: // Login
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                userManager.login(username, password);
                break;
                
            case 3: // Add Add-On
                if (userManager.getLoginStatus()) {
                    cout << "Enter add-on to add: ";
                    getline(cin, addOn);
                    userManager.addAddOnToBook(addOn);
                } else {
                    cout << "You need to log in first.\n";
                }
                break;
                
            case 4: // Remove Add-On
                if (userManager.getLoginStatus()) {
                    cout << "Enter add-on to remove: ";
                    getline(cin, addOn);
                    userManager.removeAddOnFromBook(addOn);
                } else {
                    cout << "You need to log in first.\n";
                }
                break;
                
            case 5: // Show Add-Ons
                userManager.showAddOns();
                break;
                
            case 6: // Logout
                userManager.logout();
                break;
                
            case 7: // Exit
                cout << "Exiting the program...\n";
                return 0;
                
            default:
                cout << "Invalid option. Please choose between 1 and 7.\n";
        }
    }
    
    return 0;
}

