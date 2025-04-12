#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    virtual void display() const = 0;
    virtual ~Item() {}
};

class Book : public Item {
private:
    string title, author;
    int pages;
public:
    Book() {}
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    string getTitle() const { return title; }
    int getPages() const { return pages; }

    void display() const override {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

class Newspaper : public Item {
private:
    string name, date, edition;
public:
    Newspaper() {}
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}

    string getName() const { return name; }
    string getEdition() const { return edition; }

    void display() const override {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
};

class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;
public:
    void addBook(const Book& b) {
        if (bookCount < 10) {
            books[bookCount++] = b;
        }
    }

    void addNewspaper(const Newspaper& n) {
        if (newspaperCount < 10) {
            newspapers[newspaperCount++] = n;
        }
    }

    void displayCollection() const {
        for (int i = 0; i < bookCount; ++i)
            books[i].display();
        for (int i = 0; i < newspaperCount; ++i)
            newspapers[i].display();
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; ++i) {
            for (int j = i + 1; j < bookCount; ++j) {
                if (books[i].getPages() > books[j].getPages()) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; ++i) {
            for (int j = i + 1; j < newspaperCount; ++j) {
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getTitle() == title)
                return &books[i];
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; ++i) {
            if (newspapers[i].getName() == name)
                return &newspapers[i];
        }
        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library lib;
    lib.addBook(book1);
    lib.addBook(book2);
    lib.addNewspaper(newspaper1);
    lib.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    lib.displayCollection();

    lib.sortBooksByPages();
    lib.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    lib.displayCollection();

    Book* foundBook = lib.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    } else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNews = lib.searchNewspaperByName("The Times");
    if (foundNews) {
        cout << "\nFound Newspaper:\n";
        foundNews->display();
    } else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
