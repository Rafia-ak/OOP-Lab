#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book{
private:
    string title;
    string author;
    string isbn;
    
public:
    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbn() const { return isbn; }
};

class Catalog{
private:
    vector<Book*> catalog;
    
public:
    void addBookToCatalog(Book* book){
        catalog.push_back(book);
    }

    Book* findBookByIsbn(const string& isbn){
        for (Book* book : catalog){
            if (book->getIsbn() == isbn){
                return book;
            }
        }
        return nullptr;
    }
};

class Library{
private:
    string name;
    string address;
    Catalog catalog;
    vector<Book*> books;
    
public:
    Library(string name, string address)
        : name(name), address(address), catalog(Catalog()) {}

    void addBook(Book* book){
        books.push_back(book);
        catalog.addBookToCatalog(book);
    }

    void removeBook(const string& isbn){
        for (auto it = books.begin(); it != books.end(); ++it){
            if ((*it)->getIsbn() == isbn){
                books.erase(it);
                break;
            }
        }
    }

    Book* findBookInCatalog(const string& isbn){
        return catalog.findBookByIsbn(isbn);
    }

    void showLibraryInfo(){
        cout << "Library Name: " << name << "\n";
        cout << "Library Address: " << address << "\n";
    }
};

int main(){
    Library myLibrary("The Library", "345 FLor Ln");

    Book book1("Five Feet Apart", "Rachael Lippincott", "970743273565");
    Book book2("1984", "George Orwell", "970451524935");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.showLibraryInfo();

    Book* foundBook = myLibrary.findBookInCatalog("970743273565");
    if (foundBook) {
        cout << "Found Book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << "\n";
    }
	else{
        cout << "Book not found in catalog.\n";
    }

    return 0;
}
