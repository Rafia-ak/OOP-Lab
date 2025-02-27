#include <iostream>
#include <vector>
using namespace std;

class Car{
private:
    string name;
    int id;

public:
    Car(string n, int i) : name(n), id(i) {
        cout << "Car constructed: " << name << " (ID: " << id << ")" << endl;
    }

    ~Car() {
        cout << "Car destroyed: " << name << " (ID: " << id << ")" << endl;
    }

    string getName() const { return name; }
    int getId() const { return id; }
};

class Garage{
private:
    vector<Car*> cars;

public:
    void parkCar(Car* car){
        cars.push_back(car);
        cout << "Car parked: " << car->getName() << " (ID: " << car->getId() << ")" << endl;
    }

    void listCars() const{
        cout << "Cars in garage:" << endl;
        for (const auto& car : cars){
            cout << "- " << car->getName() << " (ID: " << car->getId() << ")" << endl;
        }
    }
};

int main(){
    Car car1("Mazda", 101);
    Car car2("Audi", 102);
    Car car3("Toyota", 103);

    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    myGarage.parkCar(&car3);

    myGarage.listCars();

    cout << "End of main, cars will be destroyed automatically." << endl;
    return 0;
}
