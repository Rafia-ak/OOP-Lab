#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 7) { 
        cout << "Usage: " << argv[0] << " <Movie Name> <Adult Ticket Price> <Child Ticket Price> <Adult Tickets Sold> <Child Tickets Sold> <Donation Percentage>\n";
        return 1;
    }

    string movieName = argv[1];  
    float adultTicketPrice = stof(argv[2]);  
    float childTicketPrice = stof(argv[3]);  
    int adultTicketsSold = stoi(argv[4]);  
    int childTicketsSold = stoi(argv[5]);  
    float donationPercentage = stof(argv[6]);  

    int totalTicketsSold = adultTicketsSold + childTicketsSold;
    float grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    float donationAmount = (donationPercentage / 100) * grossAmount;
    float netSale = grossAmount - donationAmount;

    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "Movie Name:                  " << movieName << "\n";
    cout << "Number of Tickets Sold:       " << totalTicketsSold << "\n";
    cout << "Gross Amount:                $" << grossAmount << "\n";
    cout << "Percentage of Gross Donated:  " << donationPercentage << "%\n";
    cout << "Amount Donated:              $" << donationAmount << "\n";
    cout << "Net Sale:                    $" << netSale << "\n";
	cout << "\n\n";
	
    return 0;
}
