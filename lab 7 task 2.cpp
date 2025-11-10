/*Design an inventory class that stores the following members: 
serialNum: An integer that holds a part's serial number. 
manufactYear: An integer that holds the year the part was manufactured. 
lotNum: An integer that holds the part's lot number. 

The class should have appropriate member functions for storing data into, and retrieving data from, these members. 
Next, design a stack class that can hold objects of the class described above. 
Last, design a program that uses the stack class described above. 
The program should have a loop that asks the user if he or she wishes to add a part to inventory, or take a part from inventory. The loop should repeat until the user is finished. 
If the user wishes to add a part to inventory, the program should ask for the serial number, year of manufacture, and lot number. 
The data should be stored in an inventory object, and pushed onto the stack. 
If the user wishes to take a part from inventory, the program should pop the top-most part from the stack and display the contents of its member variables. 
When the user finishes the program, it should display the contents of the member values of all the objects that remain on the stack. [implement using linklist]
*/
#include <iostream>
using namespace std;
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    Inventory() {
        serialNum = manufactYear = lotNum = 0;
    }

    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void display() const {
        cout << "Serial Number: " << serialNum
             << ", Year: " << manufactYear
             << ", Lot Number: " << lotNum << endl;
    }
};
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory inv) {
        data = inv;
        next = nullptr;
    }
};
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    // Push a new inventory object
    void push(Inventory inv) {
        Node* newNode = new Node(inv);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory successfully.\n";
    }

    // Pop top inventory object
    bool pop() {
        if (isEmpty()) {
            cout << "Inventory Stack is empty. Nothing to remove.\n";
            return false;
        }
        Node* temp = top;
        cout << "\nRemoved part details:\n";
        temp->data.display();
        top = top->next;
        delete temp;
        return true;
    }

    // Peek top element
    void peek() {
        if (isEmpty()) {
            cout << "Inventory Stack is empty.\n";
            return;
        }
        cout << "\nTop part in inventory:\n";
        top->data.display();
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all parts
    void displayAll() {
        if (isEmpty()) {
            cout << "No parts left in inventory.\n";
            return;
        }
        cout << "\nParts remaining in inventory:\n";
        Node* temp = top;
        int count = 1;
        while (temp != nullptr) {
            cout << count++ << ". ";
            temp->data.display();
            temp = temp->next;
        }
    }

    // Destructor to clean memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack inventoryStack;
    int choice;

    do {
        cout << "\n*********** Inventory Menu ***********\n";
        cout << "1. Add a part to inventory\n";
        cout << "2. Take a part from inventory\n";
        cout << "3. View top part in inventory\n";
        cout << "4. Display all remaining parts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int s, y, l;
            cout << "\nEnter Serial Number: ";
            cin >> s;
            cout << "Enter Year of Manufacture: ";
            cin >> y;
            cout << "Enter Lot Number: ";
            cin >> l;
            Inventory inv;
            inv.setData(s, y, l);
            inventoryStack.push(inv);
            break;
        }
        case 2:
            inventoryStack.pop();
            break;
        case 3:
            inventoryStack.peek();
            break;
        case 4:
            inventoryStack.displayAll();
            break;
        case 0:
            cout << "\nExiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    cout << "\nFinal Inventory State:\n";
    inventoryStack.displayAll();

    return 0;
}
