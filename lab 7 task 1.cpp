#include <iostream>
#include <string>
using namespace std;
class Book {
public:
    string title;
    float price;
    int edition;
    int pages;

    // Constructor
    Book() {}
    Book(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
    }

    // Display function
    void display() const {
        cout << "Title: " << title
             << ", Price: " << price
             << ", Edition: " << edition
             << ", Pages: " << pages << endl;
    }
};

#define MAX 10
class BookStack {
    int top;
    Book books[MAX];

public:
    BookStack() { top = -1; }

    bool push(Book b) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot add more books.\n";
            return false;
        }
        books[++top] = b;
        cout << "Book \"" << b.title << "\" pushed into stack.\n";
        return true;
    }

    Book pop() {
        if (top < 0) {
            cout << "Stack Underflow! No books to pop.\n";
            return Book();
        }
        cout << "Book \"" << books[top].title << "\" popped from stack.\n";
        return books[top--];
    }

    Book peek() {
        if (top < 0) {
            cout << "Stack is Empty.\n";
            return Book();
        }
        return books[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nBooks currently in stack:\n";
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". ";
            books[i].display();
        }
    }
};


int main() {
    BookStack stack;

    // Push 5 books
    stack.push(Book("C++ Basics", 550.0, 2, 320));
    stack.push(Book("Data Structures", 700.0, 3, 480));
    stack.push(Book("Algorithms", 850.0, 1, 500));
    stack.push(Book("OOP Concepts", 600.0, 4, 350));
    stack.push(Book("Database Systems", 900.0, 2, 450));

    // Find the top element
    cout << "\nTop Book in Stack:\n";
    stack.peek().display();

    // Pop 2 books
    stack.pop();
    stack.pop();

    // Display remaining books
    stack.displayAll();

    return 0;
}
