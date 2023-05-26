#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(const string& accNumber, const string& accHolder)
        : accountNumber(accNumber), accountHolderName(accHolder), balance(0.0) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Current balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance. Withdrawal canceled." << endl;
        }
    }
};

int main() {
    vector<BankAccount> accounts;

    cout << "Bank Account Management" << endl;
    cout << "-----------------------" << endl;

    while (true) {
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Account Balance" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountNumber, accountHolderName;
                cout << "Enter the account number: ";
                cin >> accountNumber;
                cout << "Enter the account holder's name: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, accountHolderName);

                BankAccount newAccount(accountNumber, accountHolderName);
                accounts.push_back(newAccount);

                cout << "Account created successfully." << endl;
                break;
            }
            case 2: {
                string accountNumber;
                double amount;

                cout << "Enter the account number: ";
                cin >> accountNumber;
                cout << "Enter the amount to deposit: $";
                cin >> amount;

                bool accountFound = false;
                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        account.deposit(amount);
                        accountFound = true;
                        break;
                    }
                }

                if (!accountFound) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 3: {
                string accountNumber;
                double amount;

                cout << "Enter the account number: ";
                cin >> accountNumber;
                cout << "Enter the amount to withdraw: $";
                cin >> amount;

                bool accountFound = false;
                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        account.withdraw(amount);
                        accountFound = true;
                        break;
                    }
                }

                if (!accountFound) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter the account number: ";
                cin >> accountNumber;

                bool accountFound = false;
                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        cout << "Account Number: " << account.getAccountNumber() << endl;
                        cout << "Account Holder: " << account.getAccountHolderName() << endl;
                        cout << "Account Balance: $" << account.getBalance() << endl;
                        accountFound = true;
                        break;
                    }
                }

                if (!accountFound) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}

