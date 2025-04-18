#include <iostream>
using namespace std;

class car{
protected:
  string model;
  double price;

public:
  void setModel(string m)
  {
    model = m;
  }
  virtual void setPrice(double p) = 0;
  void display()
  {
    cout << "price: " << price << " model: " << model << endl;
  }
};

class color : public car{
public:
  void setPrice(double p)
  {
    price = p;
  }
};

class company : public car{
public:
  void setPrice(double p)
  {
    price = p;
  }
};

int main(){
  color color;
  company company;
  color.setModel("color model");
  color.setPrice(1000);
  company.setModel("company model");
  company.setPrice(2000);
  cout << "color details: " << endl;
  color.display();
  cout << "company details: " << endl;
  company.display();
}