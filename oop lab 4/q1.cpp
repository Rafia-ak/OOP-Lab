#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * M_PI * radius;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <radius>\n";
        return 1;
    }
    
    double radius = atof(argv[1]);
    if (radius <= 0) {
        cerr << "Please provide a valid positive radius.\n";
        return 1;
    }
    
    Circle circle(radius);
    
    cout << "Circle with radius: " << radius << "\n";
    cout << "Area: " << circle.getArea() << "\n";
    cout << "Perimeter: " << circle.getPerimeter() << "\n";
    
    return 0;
}
