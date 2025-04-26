#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TodoList {
private:
    string fileName;

    void updateFile(const vector<string>& tasks) {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (const auto& task : tasks) {
                outFile << task << endl;
            }
            outFile.close();
        }
    }

public:
    TodoList(string fileName) {
        this->fileName = fileName;
    }

    void addTask(string task) {
        vector<string> tasks;
        string line;
        ifstream inFile(fileName);
        while (getline(inFile, line)) {
            tasks.push_back(line);
        }
        inFile.close();

        tasks.push_back(task);
        updateFile(tasks);
    }

    void viewTasks() {
        ifstream inFile(fileName);
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    void markTaskAsDone(int taskIndex) {
        vector<string> tasks;
        string line;
        ifstream inFile(fileName);
        int index = 0;
        while (getline(inFile, line)) {
            if (index == taskIndex) {
                line = "[Done] " + line;
            }
            tasks.push_back(line);
            index++;
        }
        inFile.close();

        updateFile(tasks);
    }
};

int main() {
    TodoList todo("tasks.txt");

    todo.addTask("Finish homework");
    todo.addTask("Go to the gym");
    todo.addTask("Read a book");

    cout << "All tasks:" << endl;
    todo.viewTasks();

    todo.markTaskAsDone(1);

    cout << "\nTasks after marking one as done:" << endl;
    todo.viewTasks();

    return 0;
}
