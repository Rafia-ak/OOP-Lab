#include <iostream>

using namespace std;

class Student{
private:
    const int roll_no;
public:
    Student(int roll) : roll_no(roll) {}
    
    void display(){
        cout << "Student Roll Number: " << roll_no << "\n";
    }
};

int main(int argc, char* argv[]){
    if (argc < 2){
        cout << "Please provide a roll number as a command-line argument.\n";
        return 1;
    }
    
    int roll = stoi(argv[1]);
    Student student(roll);
    student.display();
    
    return 0;
}
