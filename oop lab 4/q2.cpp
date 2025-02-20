#include <iostream>
#include <cstdlib>

using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        balance = (initialBalance >= 0) ? initialBalance : 0;
        cout << "Initial Balance: " << balance << "\n";
    }

    void credit(double amount) {
        balance += amount;
        cout << "Credited: " << amount << "\n";
        cout << "New Balance after credit: " << balance << "\n";
    }

    void debit(double amount) {
        cout << "Attempting to debit: " << amount << "\n";
        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
        } else {
            balance -= amount;
            cout << "New Balance after debit: " << balance << "\n";
        }
    }

    double getBalance() {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <initial_balance> <credit_amount> <debit_amount>\n";
        return 1;
    }

    double initialBalance = atof(argv[1]);
    double creditAmount = atof(argv[2]);
    double debitAmount = atof(argv[3]);

    Account acc(initialBalance);
    acc.credit(creditAmount);
    acc.debit(debitAmount);

    cout << "Final Balance: " << acc.getBalance() << "\n";

    return 0;
}

