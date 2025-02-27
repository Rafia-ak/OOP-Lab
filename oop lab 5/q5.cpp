#include <iostream>
using namespace std;

class Car{
public:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

    void setValues(int hp, int capacity, int speakers) const{
        const_cast<Car*>(this)->engine_horsepower = hp;
        const_cast<Car*>(this)->seating_capacity = capacity;
        const_cast<Car*>(this)->no_of_speakers = speakers;
    }

    void display() const{
        cout << "Engine Horsepower: " << engine_horsepower << "\n";
        cout << "Seating Capacity: " << seating_capacity << "\n";
        cout << "Number of Speakers: " << no_of_speakers << "\n";
    }
};

int main(){
    Car myCar;
    myCar.setValues(300, 5, 6);
    myCar.display();
    return 0;
}
