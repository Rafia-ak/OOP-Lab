#include <iostream>
using namespace std;

class Person {
protected:
    int empID;

public:
    Person(int id) : empID(id) {}

    void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float salary;

public:
    Admin(int id, string empName, float empSalary) : Person(id), name(empName), salary(empSalary) {}

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << "\nMonthly Salary: " << salary << endl;
        cout << "Annual Bonus: " << (salary * 12 * 0.05) << endl;
    }
};

class Accounts : public Person {
protected:
    string name;
    float salary;

public:
    Accounts(int id, string empName, float empSalary) : Person(id), name(empName), salary(empSalary) {}

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << "\nMonthly Salary: " << salary << endl;
        cout << "Annual Bonus: " << (salary * 12 * 0.05) << endl;
    }
};

int main() {
    Admin admin(101, "Alice", 5000.0);
    Accounts acc(202, "Bob", 4500.0);

    cout << "\nAdmin Employee Information:\n";
    admin.displayData();

    cout << "\nAccounts Employee Information:\n";
    acc.displayData();

    return 0;
}