#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<int> coefficients;

public:
    Polynomial() {}

    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i)
            result[i] += coefficients[i];

        for (size_t i = 0; i < other.coefficients.size(); ++i)
            result[i] += other.coefficients[i];

        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        for (size_t i = p.coefficients.size(); i-- > 0;) {
            if (p.coefficients[i] != 0) {
                os << (p.coefficients[i] > 0 && i != p.coefficients.size() - 1 ? " + " : " ")
                   << p.coefficients[i] << "x^" << i;
            }
        }
        return os;
    }
};

int main() {
    Polynomial p1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial p2({0, 1, 4});  // 4x^2 + x

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << (p1 + p2) << endl;

    return 0;
}