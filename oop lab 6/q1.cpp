#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double interest)
        : BankAccount(accNum, initialBalance), interestRate(interest) {}

    void applyInterest() {
        balance += balance * interestRate;
    }

    void deposit(double amount) override {
        BankAccount::deposit(amount);
        applyInterest();
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double initialBalance, double overdraft)
        : BankAccount(accNum, initialBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

class BusinessAccount : public BankAccount {
private:
    double corporateTaxRate;

public:
    BusinessAccount(string accNum, double initialBalance, double taxRate)
        : BankAccount(accNum, initialBalance), corporateTaxRate(taxRate) {}

    void deposit(double amount) override {
        double taxDeduction = amount * corporateTaxRate;
        BankAccount::deposit(amount - taxDeduction);
        cout << "Corporate tax of $" << taxDeduction << " withheld from deposit." << endl;
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Corporate Tax Rate: " << corporateTaxRate * 100 << "%" << endl;
    }
};

class Employee {
protected:
    string name;

public:
    Employee(string empName) : name(empName) {}

    virtual void displayRole() const = 0;
    virtual ~Employee() {}
};

class Teller : public Employee {
public:
    Teller(string empName) : Employee(empName) {}

    void displayRole() const override {
        cout << name << " is a Teller. They can deposit, withdraw, or freeze accounts." << endl;
    }

    void freezeAccount(BankAccount& account) {
        cout << "Account " << account.getAccountNumber() << " has been frozen by " << name << "." << endl;
    }
};

class Manager : public Teller {
public:
    Manager(string empName) : Teller(empName) {}

    void displayRole() const override {
        cout << name << " is a Manager. They can deposit, withdraw, freeze, or adjust account limits." << endl;
    }

    void adjustAccountLimit(BankAccount& account, double newLimit) {
        CheckingAccount* checkingAccount = dynamic_cast<CheckingAccount*>(&account);
        if (checkingAccount) {
            checkingAccount->withdraw(newLimit);
            cout << "Overdraft limit adjusted by " << name << " to $" << newLimit << endl;
        } else {
            cout << "Cannot adjust limit for non-checking accounts." << endl;
        }
    }
};

class Customer : public Employee {
public:
    Customer(string empName) : Employee(empName) {}

    void displayRole() const override {
        cout << name << " is a Customer. They can deposit or withdraw from their accounts." << endl;
    }
};

void displayAccountOperations(vector<BankAccount*>& accounts) {
    for (auto& account : accounts) {
        account->displayAccountInfo();
        cout << "-------------------------------------------------" << endl;
    }
}

int main() {
    SavingsAccount savings("S123", 1000, 0.02);
    CheckingAccount checking("C456", 500, 200);
    BusinessAccount business("B789", 10000, 0.05);

    Customer customer("John");
    Teller teller("Jane");
    Manager manager("Alice");

    customer.displayRole();
    teller.displayRole();
    manager.displayRole();

    cout << endl;

    vector<BankAccount*> accounts = { &savings, &checking, &business };
    displayAccountOperations(accounts);

    savings.deposit(200);
    checking.withdraw(100);
    business.deposit(1000);

    displayAccountOperations(accounts);

    teller.freezeAccount(savings);

    manager.adjustAccountLimit(checking, 300);

    return 0;
}

