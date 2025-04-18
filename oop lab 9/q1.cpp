#include <iostream>
using namespace std;

class Wallet{
    double balance;
    double TotalDailyDeposit;
    double TotalDailyWithdrawal;
    double maxDailyDeposit = 5000;
    double maxDailyWithdrawal = 3000;

public:
    Wallet() : balance(0), TotalDailyDeposit(0), TotalDailyWithdrawal(0) {}

    void deposit(double amount) {
        if (amount <= 0 || amount + TotalDailyDeposit > maxDailyDeposit) {
            cout << "? Deposit of " << amount << " failed. ";
            if (amount <= 0) {
                cout << "Amount must be positive!" << endl;
            } else {
                cout << "Daily deposit limit exceeded!" << endl;
            }
            return;
        }
        balance += amount;
        TotalDailyDeposit += amount;
        cout << "? Amount: " << amount << " deposited successfully!" << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance || amount + TotalDailyWithdrawal > maxDailyWithdrawal) {
            cout << "? Withdrawal of " << amount << " failed. ";
            if (amount <= 0) {
                cout << "Amount must be positive!" << endl;
            } else if (amount > balance) {
                cout << "Insufficient balance!" << endl;
            } else {
                cout << "Daily withdrawal limit exceeded!" << endl;
            }
            return;
        }
        balance -= amount;
        TotalDailyWithdrawal += amount;
        cout << "? Amount: " << amount << " withdrew successfully!" << endl;
    }

    void showBalance() const {
        cout << "?? Current Balance: " << balance << endl;
    }
};

class User {
    string name;
    int ID;
    Wallet wallet;  

public:
    User(string n, int id) : name(n), ID(id) {}

    void deposit(double amount) {
        wallet.deposit(amount);  
    }

    void withdraw(double amount) {
        wallet.withdraw(amount);  
    }

    void showBalance() {
        cout << "User: " << name << " (" << ID << ")" << endl;
        wallet.showBalance();  
    }
};

int main(){
    User u1("Zain", 1);
    User u2("Aiman", 2);

    u1.deposit(2000);
    u1.withdraw(500);
    u1.withdraw(3000);  
    u1.deposit(4000);  
    u1.showBalance();

    cout << endl;

    u2.deposit(1000);
    u2.withdraw(1200);  
    u2.withdraw(800);
    u2.showBalance();

    return 0;
}
