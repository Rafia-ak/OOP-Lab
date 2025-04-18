#include <iostream>
using namespace std;

class shape{
public:
  virtual double getArea() = 0;
};

class Rectangle : public shape{
  int length, breadth;

public:
  Rectangle(int l, int b) : length(l), breadth(b) {}
  double getArea() override
  {
    return length * breadth;
  }
};

class Triangle : public shape{
  int height, length;

public:
  Triangle(int h, int l) : height(h), length(l) {}
  double getArea() override
  {
    return 0.5 * height * length;
  }
};

int main(){
  shape *s1;
  Triangle t(2,2);
  Rectangle r(3,3);
  s1=&t;
  cout<<s1->getArea()<<endl;
  s1=&r;
  cout<<s1->getArea();

}