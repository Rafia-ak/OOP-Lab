#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    int positionX, positionY;
    int borderThickness;
public:
    Shape(string col, int x, int y, int border = 1)
        : color(col), positionX(x), positionY(y), borderThickness(border) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string col, int x, int y, double r, int border = 1)
        : Shape(col, x, y, border), radius(r) {}

    void draw() override {
        cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with radius " << radius << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string col, int x, int y, double w, double h, int border = 1)
        : Shape(col, x, y, border), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with width " << width << " and height " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double base, height, side1, side2, side3;
public:
    Triangle(string col, int x, int y, double b, double h, double s1, double s2, double s3, int border = 1)
        : Shape(col, x, y, border), base(b), height(h), side1(s1), side2(s2), side3(s3) {}

    void draw() override {
        cout << "Drawing Triangle at (" << positionX << ", " << positionY << ") with base " << base << " and height " << height << endl;
    }

    double calculateArea() override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle c("Red", 10, 10, 5);
    Rectangle r("Blue", 5, 5, 10, 4);
    Triangle t("Green", 2, 2, 6, 4, 5, 5, 6);

    c.draw();
    cout << "Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << endl;

    r.draw();
    cout << "Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << endl;

    t.draw();
    cout << "Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << endl;

    return 0;
}
