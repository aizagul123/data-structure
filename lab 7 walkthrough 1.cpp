// C++ program to Implement a stack
// using singly linked list


#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        //while (!isEmpty()) {
            //pop();
        }
    
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();

    // ? Pop only the first (top) element once
    s.pop();

    s.display();

    return 0;
}
