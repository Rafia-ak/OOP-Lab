#include <iostream>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

public:
    BigInteger(const string& num) {
        isNegative = num[0] == '-';
        
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); --i)
            digits.push_back(num[i] - '0');
    }

    friend ostream& operator<<(ostream& os, const BigInteger& b) {
        if (b.isNegative) os << "-";
        for (auto it = b.digits.rbegin(); it != b.digits.rend(); ++it)
            os << *it;
        return os;
    }
};

int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("-98765432109876543210");

    cout << "BigInteger 1: " << num1 << endl;
    cout << "BigInteger 2: " << num2 << endl;

    return 0;
}