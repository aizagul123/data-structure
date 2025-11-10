#include <iostream>
using namespace std;

// Inventory class
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    Inventory() : serialNum(0), manufactYear(0), lotNum(0) {}

    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void display() {
        cout << "Serial Number: " << serialNum
             << ", Year: " << manufactYear
             << ", Lot Number: " << lotNum << endl;
    }
};

// Node class for Linked List Stack
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory inv) {
        data = inv;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Push operation
    void push(Inventory inv) {
        Node* newNode = new Node(inv);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    Inventory pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot remove item.\n";
            return Inventory();
        } else {
            Node* temp = top;
            Inventory poppedData = temp->data;
            top = top->next;
            delete temp;
            return poppedData;
        }
    }

    // Display all remaining items
    void displayAll() {
        if (isEmpty()) {
            cout << "No parts left in inventory.\n";
            return;
        }

        cout << "\nRemaining parts in inventory:\n";
        Node* current = top;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }
};

// Main program
int main() {
    Stack inventoryStack;
    int choice;

    cout << "===== Inventory Management using Stack =====\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Add a part to inventory (Push)\n";
        cout << "2. Take a part from inventory (Pop)\n";
        cout << "3. Exit and display remaining inventory\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Inventory inv;
            int serial, year, lot;
            cout << "\nEnter Serial Number: ";
            cin >> serial;
            cout << "Enter Year of Manufacture: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            inv.setData(serial, year, lot);
            inventoryStack.push(inv);
            cout << "Part added successfully.\n";
            break;
        }

        case 2: {
            if (!inventoryStack.isEmpty()) {
                Inventory removed = inventoryStack.pop();
                cout << "\nPart removed from inventory:\n";
                removed.display();
            } else {
                cout << "\nInventory is empty.\n";
            }
            break;
        }

        case 3:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    // Display remaining items
    inventoryStack.displayAll();

    cout << "\nProgram ended.\n";
    return 0;
}
