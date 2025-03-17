#include <iostream>
#include <string>

using namespace std;

class Books {
protected:
    string genre;

public:
    Books(string bookGenre) : genre(bookGenre) {}

    virtual void displayBookDetails() const = 0;

    virtual ~Books() {}
};

class Novel : public Books {
private:
    string title;
    string author;

public:
    Novel(string bookTitle, string bookAuthor)
        : Books("Novel"), title(bookTitle), author(bookAuthor) {}

    void displayBookDetails() const override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;

public:
    Mystery(string bookTitle, string bookAuthor)
        : Books("Mystery"), title(bookTitle), author(bookAuthor) {}

    void displayBookDetails() const override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel novel("Harry Potter", "J.K. Rowling");
    Mystery mystery("Gone Girl", "Gillian Flynn");

    cout << "Book 1 details:" << endl;
    novel.displayBookDetails();
    cout << endl;

    cout << "Book 2 details:" << endl;
    mystery.displayBookDetails();

    return 0;
}

