#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
    string name, address, phoneNumber, email;
    int id;
public:
    virtual void displayInfo() = 0;
    virtual void updateInfo(string name, string address, string phoneNumber, string email, int id) {
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->id = id;
    }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    float GPA;
    int enrollmentYear;
public:
    void displayInfo() override {
        cout << "Student ID: " << id << "\nName: " << name << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
    }
    void updateInfo(string name, string address, string phoneNumber, string email, int id, vector<string> courses, float GPA, int year) {
        Person::updateInfo(name, address, phoneNumber, email, id);
        coursesEnrolled = courses;
        this->GPA = GPA;
        enrollmentYear = year;
    }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    float salary;
public:
    void displayInfo() override {
        cout << "Professor ID: " << id << "\nName: " << name << "\nDepartment: " << department << "\nSalary: " << salary << endl;
    }
    void updateInfo(string name, string address, string phoneNumber, string email, int id, string department, vector<string> courses, float salary) {
        Person::updateInfo(name, address, phoneNumber, email, id);
        this->department = department;
        coursesTaught = courses;
        this->salary = salary;
    }
};

class Staff : public Person {
    string department, position;
    float salary;
public:
    void displayInfo() override {
        cout << "Staff ID: " << id << "\nName: " << name << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
    void updateInfo(string name, string address, string phoneNumber, string email, int id, string department, string position, float salary) {
        Person::updateInfo(name, address, phoneNumber, email, id);
        this->department = department;
        this->position = position;
        this->salary = salary;
    }
};

class Course {
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    void registerStudent(Student student) {}
    float calculateGrades() { return 0; }
};

int main() {
    Student s1;
    s1.updateInfo("Rafia", "123 Street", "123456789", "rafia@example.com", 1, {"Math", "Physics"}, 3.8, 2022);
    s1.displayInfo();

    Professor p1;
    p1.updateInfo("Dr. Smith", "456 Avenue", "987654321", "smith@uni.edu", 101, "Computer Science", {"OOP", "Algorithms"}, 90000);
    p1.displayInfo();

    Staff st1;
    st1.updateInfo("John", "789 Road", "111222333", "john@uni.edu", 201, "Administration", "Clerk", 30000);
    st1.displayInfo();

    return 0;
}