#include <iostream>
using namespace std;

class Book {
private:
    string bookName, isbn, author, publisher;

public:
    Book(string bookName, string isbn, string author, string publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() { return this->bookName; }
    string getISBN() { return this->isbn; }
    string getAuthor() { return this->author; }
    string getPublisher() { return this->publisher; }

    string getBookInfo() {
        return "Book Name: " + this->bookName + ", ISBN: " + this->isbn + ", Author: " + this->author + ", Publisher: " + this->publisher;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 21) return 1;
    Book books[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };
    for (int i = 0; i < 5; i++) cout << books[i].getBookInfo() << endl;
    return 0;
}