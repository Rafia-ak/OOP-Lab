#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Logger {
private:
    string logFileName;
    size_t maxFileSize;

    bool isFileTooLarge() {
        ifstream inFile(logFileName, ios::ate);
        return inFile.tellg() > maxFileSize;
    }

    void rotateLogs() {
        int index = 1;
        string newFileName = "log" + to_string(index) + ".txt";
        while (ifstream(newFileName)) {
            index++;
            newFileName = "log" + to_string(index) + ".txt";
        }
        rename(logFileName.c_str(), newFileName.c_str());
    }

public:
    Logger(string fileName, size_t maxSize = 1048576) {
        logFileName = fileName;
        maxFileSize = maxSize;
    }

    void log(string message) {
        if (isFileTooLarge()) {
            rotateLogs();
        }

        ofstream outFile(logFileName, ios_base::app);
        if (outFile.is_open()) {
            outFile << message << endl;
            outFile.close();
        } else {
            cout << "Failed to open log file!" << endl;
        }
    }
};

int main() {
    Logger logger("log.txt");

    logger.log("Log message 1");
    logger.log("Log message 2");
    logger.log("Log message 3");

    return 0;
}
