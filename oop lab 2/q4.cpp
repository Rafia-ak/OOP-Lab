#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
    int employee_id;
    char name[50];
    double salary;
};

struct Organisation {
    char organisation_name[50];
    char organisation_number[50];
    Employee emp;
    
    void displayDetails() {
        cout << "Organisation Name: " << organisation_name << endl;
        cout << "Organisation Number: " << organisation_number << endl;
        cout << "Employee ID: " << emp.employee_id << endl;
        cout << "Employee Name: " << emp.name << endl;
        cout << "Employee Salary: " << emp.salary << endl;
    }
};

int main(int argc, char *argv[]){
    Organisation org;

    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");
    
    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;

    cout << "The size of structure Organisation: " << sizeof(org) << endl;

    org.displayDetails();

    return 0;
}
