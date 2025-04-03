#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
public:
    Account(int accNum, double bal, string name) : accountNumber(accNum), balance(bal), accountHolderName(name) {}
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { if (balance >= amount) balance -= amount; }
    virtual void calculateInterest() = 0;
    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;
public:
    SavingsAccount(int accNum, double bal, string name, double rate, double minBal) 
        : Account(accNum, bal, name), interestRate(rate), minimumBalance(minBal) {}
    void calculateInterest() override {
        balance += balance * (interestRate / 100);
    }
    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) balance -= amount;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal, string name) : Account(accNum, bal, name) {}
    void calculateInterest() override {}
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    int maturityDate;
public:
    FixedDepositAccount(int accNum, double bal, string name, double rate, int maturity) 
        : Account(accNum, bal, name), fixedInterestRate(rate), maturityDate(maturity) {}
    void calculateInterest() override {
        balance += balance * (fixedInterestRate / 100);
    }
    void withdraw(double amount) override {}
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount(101, 5000, "Rafia", 2.5, 1000));
    accounts.push_back(new CheckingAccount(102, 3000, "Ahsan"));
    accounts.push_back(new FixedDepositAccount(103, 10000, "Arif", 5.0, 2027));
    
    for (auto acc : accounts) {
        acc->calculateInterest();
        acc->printStatement();
    }
    
    for (auto acc : accounts) delete acc;
    return 0;
}
