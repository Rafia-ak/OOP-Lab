#include <iostream>
#include <cstdlib>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price)
        : partNumber(partNum), partDescription(partDesc), 
          quantity(qty > 0 ? qty : 0), pricePerItem(price > 0 ? price : 0.0) {
        cout << "Part Number: " << partNumber << "\n";
        cout << "Part Description: " << partDescription << "\n";
        cout << "Quantity: " << quantity << "\n";
        cout << "Price per Item: " << pricePerItem << "\n";
    }

    double getInvoiceAmount() {
        return quantity * pricePerItem;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <part_number> <part_description> <quantity> <price_per_item>\n";
        return 1;
    }

    string partNumber = argv[1];
    string partDescription = argv[2];
    int quantity = atoi(argv[3]);
    double pricePerItem = atof(argv[4]);

    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    
    cout << "Total Invoice Amount: " << invoice.getInvoiceAmount() << "\n";

    return 0;
}

