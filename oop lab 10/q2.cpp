#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string designation;
    int yearsOfService;
public:
    Employee() {}
    Employee(int id, string name, string designation, int yearsOfService) {
        this->id = id;
        this->name = name;
        this->designation = designation;
        this->yearsOfService = yearsOfService;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getDesignation() { return designation; }
    int getYearsOfService() { return yearsOfService; }

    void incrementId() { id++; }
    void incrementYears() { yearsOfService++; }

    string toString() {
        return to_string(id) + "," + name + "," + designation + "," + to_string(yearsOfService);
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;
public:
    void loadFromFile(string fileName) {
        ifstream inFile(fileName);
        string line;
        while (getline(inFile, line)) {
            int firstComma = line.find(',');
            int secondComma = line.find(',', firstComma + 1);
            int thirdComma = line.find(',', secondComma + 1);

            string idStr = line.substr(0, firstComma);
            string name = line.substr(firstComma + 1, secondComma - firstComma - 1);
            string designation = line.substr(secondComma + 1, thirdComma - secondComma - 1);
            string yearsStr = line.substr(thirdComma + 1);

            Employee emp(stoi(idStr), name, designation, stoi(yearsStr));
            employees.push_back(emp);
        }
        inFile.close();
    }

    void saveToFile(string fileName) {
        ofstream outFile(fileName);
        for (auto& emp : employees) {
            outFile << emp.toString() << endl;
        }
        outFile.close();
    }

    vector<Employee> findManagers() {
        vector<Employee> managers;
        for (auto& emp : employees) {
            if (emp.getDesignation() == "manager" && emp.getYearsOfService() >= 2) {
                managers.push_back(emp);
            }
        }
        return managers;
    }

    void keepOnlyManagers(vector<Employee> managers) {
        employees = managers;
    }

    void incrementIdsAndYears() {
        for (auto& emp : employees) {
            emp.incrementId();
            emp.incrementYears();
        }
    }
};

int main() {
    EmployeeManager manager;
    manager.loadFromFile("employees.txt");

    vector<Employee> managers = manager.findManagers();
    manager.keepOnlyManagers(managers);
    manager.saveToFile("filtered_employees.txt");

    manager.incrementIdsAndYears();
    manager.saveToFile("updated_employees.txt");

    return 0;
}
