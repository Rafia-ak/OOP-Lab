#include <iostream>
using namespace std;

class Shape {
private:
    float area;

public:
    Shape(float a) : area(a) {}

    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    void display() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(20.5), shape2(30.2);
    cout << "Shape 1 ";
    shape1.display();
    
    cout << "Shape 2 ";
    shape2.display();
    
    Shape totalArea = shape1 + shape2;
    cout << "Total Area after Addition: ";
    totalArea.display();

    return 0;
}