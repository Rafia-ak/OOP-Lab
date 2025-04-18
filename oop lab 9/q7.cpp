#include <iostream>
using namespace std;

class person{
protected:
  int ID;
  string name;

public:
  virtual void getData()
  {
    cout << "enter name: ";
    cin >> name;
    cout << " id: ";
    cin >> ID;
  }
  virtual void displayData()
  {
    cout << " name: " << name << " id: " << ID << endl;
  }
  virtual void bonus() = 0;
};

class admin : virtual public person{
protected:
  double adminSalary;

public:
  void getData() override
  {
    cout << "enter admin data: ";
    person::getData();
    cout << " salary: ";
    cin >> adminSalary;
  }
  void bonus() override
  {
    cout << " Admin bonus: " << adminSalary * 0.2 << endl;
  }
};
class Accounts : virtual public person
{
protected:
  double AccountsSalary;

public:
  void getData() override
  {
    cout << "enter Accounts data: ";
    person::getData();
    cout << " salary: ";
    cin >> AccountsSalary;
  }
  void bonus() override
  {
    cout << " Accounts bonus: " << AccountsSalary * 0.3 << endl;
  }
};

class Master : public admin, public Accounts
{
public:
  void getData() override
  {
    person::getData();
    cout << " Enter admin salary: " << endl;
    cin >> adminSalary;
    cout << " Enter accounts salary: " << endl;
    cin >> AccountsSalary;
  }
  void displayData() override
  {
    person::displayData();
    cout << "AccountsSalary: " << AccountsSalary << " admin salary: " << adminSalary << endl;
  }
  void bonus() override
  {
    double MasterSalary = adminSalary + AccountsSalary;
    cout << "Master bonus: " << MasterSalary * 0.4;
  }
};
int main()
{
  person *p;

  Master m;
  p = &m;
  p->getData();
  p->displayData();
  p->bonus();
}