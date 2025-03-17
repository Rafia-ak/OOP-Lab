#include <iostream>
using namespace std;

class Student {
protected:
    int id;
    string name;

public:
    void setStudentDetails(int sid, string sname) {
        id = sid;
        name = sname;
    }

    void displayStudentDetails() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

class Marks : public Student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;

public:
    void setMarks(int oop, int pf, int ds, int db) {
        marks_oop = oop;
        marks_pf = pf;
        marks_ds = ds;
        marks_db = db;
    }

    void displayMarks() {
        cout << "Marks in OOP: " << marks_oop << endl;
        cout << "Marks in PF: " << marks_pf << endl;
        cout << "Marks in DS: " << marks_ds << endl;
        cout << "Marks in DB: " << marks_db << endl;
    }
};

class Result : public Marks {
protected:
    int total_marks;
    double avg_marks;

public:
    void calculateResult() {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }

    void displayResult() {
        cout << "Total Marks: " << total_marks << endl;
        cout << "Average Marks: " << avg_marks << endl;
    }
};

int main() {
    Result student;
    
    // Assigning values directly without user input
    student.setStudentDetails(101, "Ali Khan");
    student.setMarks(85, 90, 78, 88);
    student.calculateResult();
    
    cout << "\nStudent Details:\n";
    student.displayStudentDetails();
    
    cout << "\nMarks Obtained:\n";
    student.displayMarks();
    
    cout << "\nResult:\n";
    student.displayResult();

    return 0;
}

