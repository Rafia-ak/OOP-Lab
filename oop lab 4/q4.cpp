#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Book {
public:
    string author, title, publisher;
    double price;
    int stock;

    Book(string t, string a, string p, double pr, int s) 
        : title(t), author(a), publisher(p), price(pr), stock(s) {}
};

class BookShop {
private:
    vector<Book> inventory;

public:
    void addBook(Book book) {
        inventory.push_back(book);
    }

    void searchBook(string title, string author, int requestedCopies) {
        for (auto &book : inventory) {
            if (book.title == title && book.author == author) {
                cout << "Book Found!\n";
                cout << "Title: " << book.title << "\n";
                cout << "Author: " << book.author << "\n";
                cout << "Publisher: " << book.publisher << "\n";
                cout << "Price: $" << book.price << "\n";
                cout << "Stock Available: " << book.stock << "\n";

                if (requestedCopies <= book.stock) {
                    cout << "Total Cost: $" << (requestedCopies * book.price) << "\n";
                } else {
                    cout << "Required copies not in stock.\n";
                }
                return;
            }
        }
        cout << "Book not available.\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <book_title> <book_author> <requested_copies>\n";
        return 1;
    }

    string searchTitle = argv[1];
    string searchAuthor = argv[2];
    int requestedCopies = atoi(argv[3]);

    BookShop shop;
    
    shop.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 10.99, 5));
    shop.addBook(Book("1984", "George Orwell", "Secker & Warburg", 8.99, 10));
    shop.addBook(Book("Moby Dick", "Herman Melville", "Harper & Brothers", 12.50, 3));

    shop.searchBook(searchTitle, searchAuthor, requestedCopies);

    return 0;
}
