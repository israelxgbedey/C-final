#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

// Define a constant for the number of accounts
const int NUM_ACCOUNTS = 10;

// Define a structure to store the transaction data
struct Transaction {
    string account;
    double amount;
    string type;
};

// Create an array of transaction structures and initialize it with the ATM log data
Transaction transactions[] = {
    {"eRbNfOxQwf", 728.81, "deposit"},
    {"JwOqQbrTE0", 283.93, "deposit"},
    {"eRbNfOxQwf", 869.92, "withdrawal"},
    {"HL2ZFqBcCe", 784.39, "withdrawal"},
    {"P5bPQHwhZ9", 826.16, "deposit"},
    {"I5JqqmI1Uc", 128.86, "deposit"},
    {"mFC97xEcBE", 264.88, "withdrawal"},
    {"JwOqQbrTE0", 903.31, "withdrawal"}
};

// Define a function to return the transactions array
vector<tuple<string, double, string>> readLogs() {
    vector<tuple<string, double, string>> transactionsVector;
    // Loop through the transactions array
    for (int i = 0; i < 8; i++) {
        // Get the account number, amount, and type of transaction from the structure
        string account = transactions[i].account;
        double amount = transactions[i].amount;
        string type = transactions[i].type;
        // Append a tuple of the account, amount, and type to the transactions vector
        transactionsVector.push_back(make_tuple(account, amount, type));
    }
    return transactionsVector;
}

// Define a function to calculate the balance and status of each account and display the output
void calculateBalance(vector<tuple<string, double, string>> transactions) {
    // Declare and initialize arrays to store the account numbers and balances of the 10 accounts
    string accounts[NUM_ACCOUNTS] = {"eRbNfOxQwf", "JwOqQbrTE0", "HL2ZFqBcCe", "P5bPQHwhZ9", "I5JqqmI1Uc", "mFC97xEcBE", "aXyZpQrStU", "bCdEfGhIjK", "cLmNoPqRsT", "dEfGhIjKlM"};
    double balances[NUM_ACCOUNTS] = {0.0};
    // Loop through the transactions vector
    for (auto t : transactions) {
        // Get the account number, amount, and type of transaction from the tuple
        string account = get<0>(t);
        double amount = get<1>(t);
        string type = get<2>(t);
        // Find the index of the account in the accounts array
        int index = -1;
        for (int i = 0; i < NUM_ACCOUNTS; i++) {
            if (accounts[i] == account) {
                index = i;
                break;
            }
        }
        // Check if the account is valid
        if (index != -1) {
            // Update the balance according to the type of transaction
            if (type == "deposit") {
                balances[index] += amount;
            } else if (type == "withdrawal") {
                balances[index] -= amount;
            } else { // Handle the error if the type is invalid
                cout << "Error: Invalid type of transaction for account " << account << endl;
            }
        } else { // Handle the error if the account is invalid
            cout << "Error: Invalid account number " << account << endl;
        }
    }
    // Display the output
    
    // Loop through the accounts and balances arrays
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        // Display the account number and balance
        cout << accounts[i] << " " << balances[i] << " ";
        // Display the status of the account
        if (balances[i] >= 0) {
            cout << "In Good Standing" << endl;
        } else {
            cout << "Withdrawn" << endl;
        }
    }

    // Ask the user to enter log
    cout << "Please enter log : ";
    string user_account;
    cin >> user_account;
    // Find the index of the user account in the accounts array
    int user_index = -1;
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        if (accounts[i] == user_account) {
            user_index = i;
            break;
        }
    }
    // Check if the user account is valid
    if (user_index != -1) {
        // Display the user account balance and status
        cout << "Account balance is: " << balances[user_index] << endl;
        if (balances[user_index] >= 0) {
            cout << "Account is in good standing." << endl;
        } else {
            cout << "Account is withdrawn." << endl;
        }
    } else { // Handle the error if the user account is invalid
        cout << "Error: Invalid account number." << endl;
    }

    // Ask the user if they want to enter more logs
    cout << "Do you want to enter more logs? (yes/no): ";
    string more_logs;
    cin >> more_logs;
    if (more_logs == "yes") {
        // Call calculateBalance recursively for additional logs
        calculateBalance(transactions);
    } else {
        cout << "Exiting program." << endl;
    }
}

// Define the main function
int main() {
    // Return the transactions array
    vector<tuple<string, double, string>> transactions = readLogs();
    // Calculate the balance and status of each account and display the output
    calculateBalance(transactions);
    return 0;
}

