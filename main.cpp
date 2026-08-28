#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Structure to store user profile and financial state
struct User
{
    string name;
    string referrer;
    int earnings;
    vector<string> transactions; // Audit trail for bonuses and withdrawals
};

// Multi-Level Marketing (MLM) System Architecture
class MLMSystem
{
private:
    map<string, User> users; // Key-Value Store for O(log N) operations

public:
    // Register a new user in the referral network
    void registerUser(string name, string referrer = "")
    {
        if (users.find(name) != users.end())
        {
            cout << "Error: User '" << name << "' is already registered in the network!\n";
            return;
        }

        int bonus = 0;
        if (!referrer.empty() && users.find(referrer) != users.end())
        {
            users[referrer].earnings += 100; // Immediate Direct Referral Commission
            users[referrer].transactions.push_back("Credited Rs. 100 commission from direct downline: " + name);
            bonus = 100;
        }

        users[name] = {name, referrer, 0, {"Account activated in MLM network."}};
        cout << "User '" << name << "' registered successfully.\n";

        if (bonus > 0)
        {
            cout << "Referrer '" << referrer << "' credited with Rs. " << bonus << " bonus.\n";
        }
    }

    // Display user profile details
    void displayUser(string name)
    {
        if (users.find(name) == users.end())
        {
            cout << "Error: User '" << name << "' not found.\n";
            return;
        }
        User u = users[name];
        cout << "\n========================================\n";
        cout << "              USER PROFILE              \n";
        cout << "========================================\n";
        cout << "User Name      : " << u.name << "\n";
        cout << "Direct Sponsor : " << (u.referrer.empty() ? "None (Direct Root)" : u.referrer) << "\n";
        cout << "Total Earnings : Rs. " << u.earnings << "\n";
        cout << "========================================\n";
    }

    // Process balance withdrawal
    void withdrawEarnings(string name, int amount)
    {
        if (users.find(name) == users.end())
        {
            cout << "Error: User '" << name << "' not found.\n";
            return;
        }
        if (amount <= 0)
        {
            cout << "Error: Invalid withdrawal amount.\n";
            return;
        }
        if (users[name].earnings < amount)
        {
            cout << "Error: Insufficient balance! Available: Rs. " << users[name].earnings << "\n";
            return;
        }

        users[name].earnings -= amount;
        users[name].transactions.push_back("Debited Rs. " + to_string(amount) + " via withdrawal.");
        cout << "Transaction Successful: Rs. " << amount << " withdrawn.\n";
    }

    // Display transaction audit trail
    void displayTransactions(string name)
    {
        if (users.find(name) == users.end())
        {
            cout << "Error: User '" << name << "' not found.\n";
            return;
        }
        cout << "\n--- Transaction History for " << name << " ---\n";
        for (const string &t : users[name].transactions)
        {
            cout << " • " << t << "\n";
        }
    }

    // Display all active participants in the MLM hierarchy
    void displayAllUsers()
    {
        if (users.empty())
        {
            cout << "No registered members found in the network.\n";
            return;
        }
        cout << "\n============================================================\n";
        cout << "                   NETWORK DIRECTORY                        \n";
        cout << "============================================================\n";
        for (auto &u : users)
        {
            cout << " • " << u.second.name 
                 << " | Sponsor: " << (u.second.referrer.empty() ? "None" : u.second.referrer)
                 << " | Balance: Rs. " << u.second.earnings << "\n";
        }
        cout << "============================================================\n";
    }
};

int main()
{
    MLMSystem mlm;
    int choice, amount;
    string name, referrer;

    do
    {
        cout << "\n========================================\n";
        cout << "   MULTI-LEVEL MARKETING (MLM) ENGINE   \n";
        cout << "========================================\n";
        cout << "1. Register New Member\n";
        cout << "2. View Member Profile\n";
        cout << "3. Withdraw Earnings\n";
        cout << "4. View Transaction Ledger\n";
        cout << "5. Display Complete Directory\n";
        cout << "6. Exit Application\n";
        cout << "----------------------------------------\n";
        cout << "Select Option [1-6]: ";
        
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a numerical option.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                cout << "Enter member name: ";
                cin >> name;
                cout << "Enter referrer name (or 'none'): ";
                cin >> referrer;
                if (referrer == "none" || referrer == "None") referrer = "";
                mlm.registerUser(name, referrer);
                break;
            case 2:
                cout << "Enter member name: ";
                cin >> name;
                mlm.displayUser(name);
                break;
            case 3:
                cout << "Enter member name: ";
                cin >> name;
                cout << "Enter amount to withdraw (Rs.): ";
                cin >> amount;
                mlm.withdrawEarnings(name, amount);
                break;
            case 4:
                cout << "Enter member name: ";
                cin >> name;
                mlm.displayTransactions(name);
                break;
            case 5:
                mlm.displayAllUsers();
                break;
            case 6:
                cout << "Shutting down MLM engine...\n";
                break;
            default:
                cout << "Invalid option selected! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}