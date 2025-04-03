#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate;
public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() = 0;
    virtual double convertTo(string targetCurrency, double targetRate) {
        return (convertToBase() / targetRate);
    }

    virtual void displayCurrency() = 0;
    
    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(1000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "100 USD to EUR: " << d.convertTo("EUR", 1.1) << " EUR" << endl;
    cout << "100 EUR to INR: " << e.convertTo("INR", 0.012) << " INR" << endl;
    cout << "1000 INR to USD: " << r.convertTo("USD", 1.0) << " USD" << endl;

    return 0;
}
