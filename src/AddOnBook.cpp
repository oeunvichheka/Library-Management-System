#include <iostream>
#include <string>
using namespace std;
class AddOnBook {
private:
    vector<string> addOns;

public:
    // Add a new add-on to the book
    void addAddOn(const string& addOn) {
        addOns.push_back(addOn);
        cout << "Add-On '" << addOn << "' has been added!" << endl;
    }

    // Remove an add-on from the book
    void removeAddOn(const string& addOn) {
        auto it = find(addOns.begin(), addOns.end(), addOn);
        if (it != addOns.end()) {
            addOns.erase(it);
            cout << "Add-On '" << addOn << "' has been removed!" << endl;
        } else {
            cout << "Add-On '" << addOn << "' not found!" << endl;
        }
    }

    // Display all add-ons
    void showAddOns() const {
        if (addOns.empty()) {
            cout << "No add-ons in the book." << endl;
        } else {
            cout << "Current Add-Ons:" << endl;
            for (const auto& addOn : addOns) {
                cout << "- " << addOn << endl;
            }
        }
    }
};