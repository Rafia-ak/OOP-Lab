#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Subject {
    string name;
};

struct Student {
    int ID;
    vector<Subject> subjects;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Error: Missing arguments!\n";
        cout << "Correct usage: " << argv[0] << " <number_of_students> <subjects_per_student>\n";
        return 1;
    }

    int num_students = stoi(argv[1]);
    int num_subjects = stoi(argv[2]);

    if (num_students <= 0 || num_subjects <= 0) {
        cout << "Error: Number of students and subjects must be positive integers.\n";
        return 1;
    }

    vector<Student> students(num_students);

    for (int i = 0; i < num_students; ++i) {
        students[i].ID = i + 1;
        students[i].subjects.resize(num_subjects);

        cout << "Enter subjects for Student ID " << students[i].ID << ":\n";
        for (int j = 0; j < num_subjects; ++j) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> students[i].subjects[j].name;
        }
    }

    cout << "\nStored Student Information:\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << "Student ID: " << students[i].ID << "\nSubjects:\n";
        for (int j = 0; j < students[i].subjects.size(); ++j) {
            cout << "  " << students[i].subjects[j].name << "\n";
        }
    }

    return 0;
}


