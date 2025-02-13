#include <iostream>
#include <string>
using namespace std;

class Employee{
    string firstname;
    string lastname;
    double salary;
    
public:
    Employee(string f, string l, double s){
        firstname = f;
        lastname = l;
        salary = (s > 0) ? s : 0.0;
    }
    
    void setSalary(double s){
        if(s > 0)
            salary = s;
    }
    
    double getSalary(){
        return salary;
    }
    
    void giveRaise(double percentage){
        salary += salary * (percentage / 100.0);
    }
    
    void displayEmployee(){
        cout << firstname << " " << lastname << " yearly salary: " << (salary * 12) << endl;
    }
};

int main(int argc, char* argv[]){
    if (argc != 7) {
        cout << "Usage: ./q4 first1 last1 salary1 first2 last2 salary2" << endl;
        return 1;
    }
    
    Employee e1(argv[1], argv[2], atof(argv[3]));
    Employee e2(argv[4], argv[5], atof(argv[6]));
    
    cout << "Before raise:" << endl;
    e1.displayEmployee();
    e2.displayEmployee();
    
    e1.giveRaise(10);
    e2.giveRaise(10);
    
    cout << "After 10% raise:" << endl;
    e1.displayEmployee();
    e2.displayEmployee();
    
    return 0;
}
