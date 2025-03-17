#include <iostream>
#include <string>

using namespace std;

class Vehicles {
protected:
    double price;

public:
    Vehicles(double vehiclePrice) : price(vehiclePrice) {}

    virtual void displayDetails() const = 0;

    virtual ~Vehicles() {}
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numDoors;
    string fuelType;

public:
    Car(double vehiclePrice, int seatingCap, int doors, string fuel)
        : Vehicles(vehiclePrice), seatingCapacity(seatingCap), numDoors(doors), fuelType(fuel) {}

    void displayDetails() const override {
        cout << "Price: $" << price << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numCylinders;
    int numGears;
    int numWheels;

public:
    Motorcycle(double vehiclePrice, int cylinders, int gears, int wheels)
        : Vehicles(vehiclePrice), numCylinders(cylinders), numGears(gears), numWheels(wheels) {}

    void displayDetails() const override {
        cout << "Price: $" << price << endl;
        cout << "Number of Cylinders: " << numCylinders << endl;
        cout << "Number of Gears: " << numGears << endl;
        cout << "Number of Wheels: " << numWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType;

public:
    Audi(double vehiclePrice, int seatingCap, int doors, string fuel, string model)
        : Car(vehiclePrice, seatingCap, doors, fuel), modelType(model) {}

    void displayDetails() const override {
        Car::displayDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double vehiclePrice, int cylinders, int gears, int wheels, string make)
        : Motorcycle(vehiclePrice, cylinders, gears, wheels), makeType(make) {}

    void displayDetails() const override {
        Motorcycle::displayDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "Q7");
    Yamaha yamahaBike(15000, 4, 6, 2, "YZF-R1");

    cout << "Audi Car Details:" << endl;
    audiCar.displayDetails();
    cout << endl;

    cout << "Yamaha Motorcycle Details:" << endl;
    yamahaBike.displayDetails();

    return 0;
}

