#include <iostream>
using namespace std;

class FlightOperation{
public:
  virtual void bookSeat(int num) = 0;
  virtual void cancelSeat(int num) = 0;
  virtual void upgradeSeat(int index) = 0;
};

class Flight : public FlightOperation{
  int flightNum;
  string Arrival;
  string Departure;
  int capacity;
  int seats[100];

public:
  Flight(int n, string a, string d, int c) : flightNum(n), Arrival(a), Departure(d), capacity(100)
  {
    for (int i = 0; i < 100; i++)
    {
      seats[i] = 1;
    }
  }

public:
  void bookSeat(int num) override
  {
    if (num > capacity)
    {
      cout << "not enough seats to book" << endl;
      return;
    }
    int booked = 0;
    for (int i = 0; i < 100; i++)
    {
      if (seats[i] == 1)
      {
        seats[i] = 0;
        cout << "seat: " << i << " booked successfully!" << endl;
        capacity--;
        booked++;
        if (booked == num)
        {
          return;
        }
      }
    }
  }
  void cancelSeat(int index) override
  {
    if (index < 0 || index >= 100)
    {
      cout << "Invalid seat index!" << endl;
      return;
    }
    if (seats[index] == 0)
    {
      cout << "seat cancelled successfully!" << endl;
      seats[index] = 1;
      capacity++;
    }
    else
    {
      cout << "seat not booked" << endl;
    }
  }
  void upgradeSeat(int index) override
  {
    if (seats[index] == 1)
    {
      cout << "seat upgraded successfully!" << endl;
    }
    else
    {
      cout << "seat not booked yet" << endl;
    }
  }
};

class Passenger{
  int ID;
  string name;

public:
  Passenger(int id, string n) : ID(id), name(n) {}
  void requestBooking(Flight &f, int num)
  {
    f.bookSeat(num);
  }
  void cancelseat(Flight &f, int index)
  {
    f.cancelSeat(index);
  }
  void upgradeseat(Flight &f, int index)
  {
    f.upgradeSeat(index);
  }
};

int main(){
  Flight flight1(101, "New York", "London", 100); 
  Passenger passenger1(1, "Rafia Karim");
  Passenger passenger2(2, "Ahsan Arif");

  cout << "=== Flight Details ===" << endl;

  cout << "\n=== Passenger 1 Requesting Booking (2 Seats) ===" << endl;
  passenger1.requestBooking(flight1, 2);

  cout << "\n=== Passenger 2 Requesting Booking (3 Seats) ===" << endl;
  passenger2.requestBooking(flight1, 3);

  cout << "\n=== Passenger 1 Cancelling Seat (Seat 0) ===" << endl;
  passenger1.cancelseat(flight1, 0);

  cout << "\n=== Passenger 2 Upgrading Seat (Seat 1) ===" << endl;
  passenger2.upgradeseat(flight1, 1);

  cout << "\n=== Final Flight Details ===" << endl;

  return 0;
}