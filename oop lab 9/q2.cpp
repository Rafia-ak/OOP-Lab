#include <iostream>
#include <string>
using namespace std;

const int MAX_LOGS = 1000;

class Logger{
private:
    string logs[MAX_LOGS];
    int logCount = 0;

    void storeLog(const string& severity, const string& module, const string& message) {
        string fullMessage = "[" + severity + "] [" + module + "] " + message;
        if (logCount >= MAX_LOGS) {
            for (int i = 1; i < MAX_LOGS; i++) {
                logs[i - 1] = logs[i];
            }
            logs[MAX_LOGS - 1] = fullMessage;
        } else {
            logs[logCount++] = fullMessage;
        }
    }

public:
    void log(const string& severity, const string& module, const string& message) {
        storeLog(severity, module, message);
    }

    int getLogCount() const {
        return logCount;
    }

    string getLog(int index) const {
        if (index >= 0 && index < logCount) {
            return logs[index];
        }
        return "Invalid log index";
    }
};

class Auditor{
private:
    bool isAuthenticated;

public:
    Auditor(bool auth) : isAuthenticated(auth) {}

    void viewLogs(const Logger& logger) {
        if (!isAuthenticated) {
            cout << "Access denied. Auditor not authenticated.\n";
            return;
        }

        cout << "\n--- Audit Log ---\n";
        for (int i = 0; i < logger.getLogCount(); i++) {
            cout << logger.getLog(i) << endl;
        }
    }
};

int main(){
    Logger logger;
    logger.log("INFO", "Network", "Connection established.");
    logger.log("WARN", "Database", "Query took too long.");
    logger.log("ERROR", "Auth", "Login failed for user John.");
    logger.log("INFO", "Network", "Packet sent.");
    logger.log("ERROR", "Storage", "Disk space low.");

    Auditor auditor(true);
    auditor.viewLogs(logger);

    return 0;
}
