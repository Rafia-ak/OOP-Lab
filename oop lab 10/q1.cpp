#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class EncryptionHandler {
private:
    string normalText;
    string encryptedText;
public:
    EncryptionHandler(string text) {
        normalText = text;
    }

    void encrypt() {
        encryptedText = normalText;
        for (int i = 0; i < encryptedText.length(); i++) {
            encryptedText[i] = encryptedText[i] + (i + 1);
        }
    }

    void writeToFile(string fileName) {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted in file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void readFromFileAndDecrypt(string fileName) {
        ifstream inFile(fileName);
        string readEncryptedText;
        if (inFile.is_open()) {
            getline(inFile, readEncryptedText);
            inFile.close();

            string decryptedText = readEncryptedText;
            for (int i = 0; i < decryptedText.length(); i++) {
                decryptedText[i] = decryptedText[i] - (i + 1);
            }

            cout << "Decrypted text read then decoded from file:" << endl;
            cout << decryptedText << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }

    void displayNormalText() {
        cout << "Normal Text: " << normalText << endl;
    }
};

int main() {
    string userInput;
    cout << "Enter String: ";
    getline(cin, userInput);

    EncryptionHandler handler(userInput);

    handler.displayNormalText();
    handler.encrypt();
    handler.writeToFile("encrypted.txt");
    handler.readFromFileAndDecrypt("encrypted.txt");

    return 0;
}
