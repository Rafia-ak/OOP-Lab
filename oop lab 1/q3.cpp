#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <Customer ID> <Customer Name> <Units Consumed>" << endl;
        return 1;
    }

    int customerID = stoi(argv[1]);
    string customerName = argv[2];
    int unitsConsumed = stoi(argv[3]);

    double chargePerUnit = 0.0;
    if (unitsConsumed <= 199) {
        chargePerUnit = 16.20;
    } else if (unitsConsumed >= 200 && unitsConsumed < 300) {
        chargePerUnit = 20.10;
    } else if (unitsConsumed >= 300 && unitsConsumed < 500) {
        chargePerUnit = 27.10;
    } else {
        chargePerUnit = 35.90;
    }

    double amountCharges = unitsConsumed * chargePerUnit;
    double surcharge = 0.0;

    if (amountCharges > 18000) {
        surcharge = amountCharges * 0.15;
    }

    double netAmount = amountCharges + surcharge;

    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Units Consumed: " << unitsConsumed << endl;
    cout << "Amount Charges @Rs. " << chargePerUnit << " per unit: " << amountCharges << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << netAmount << endl;

    return 0;
}
