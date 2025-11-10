#include <iostream>
#include <string>
using namespace std;

struct Applicant {
    int id;
    double height, weight, vision;
    string status;
    Applicant* next;
    Applicant* prev;

    Applicant(int i, double h, double w, double v, string s) {
        id = i;
        height = h;
        weight = w;
        vision = v;
        status = s;
        next = prev = NULL;
    }
};

class ApplicantQueue {
    Applicant* front;
    Applicant* rear;

public:
    ApplicantQueue() {
        front = rear = NULL;
    }

    // Add new applicant at end
    void enqueue(Applicant* newApp) {
        if (rear == NULL) {
            front = rear = newApp;
        } else {
            rear->next = newApp;
            newApp->prev = rear;
            rear = newApp;
        }
    }

    // Remove applicant from front
    void dequeue() {
        if (front == NULL) {
            cout << "No applicants in line.\n";
            return;
        }
        cout << "Applicant " << front->id << " has given test and left the line.\n";
        Applicant* temp = front;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;
        delete temp;
    }

    // Remove applicant at specific position (e.g. 2nd)
    void removeAtPosition(int pos) {
        if (front == NULL) return;
        Applicant* temp = front;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Invalid position!\n";
            return;
        }

        cout << "Applicant " << temp->id << " had urgency and left the line.\n";

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            front = temp->next; // removing first

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        else
            rear = temp->prev; // removing last

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "No applicants in queue.\n";
            return;
        }
        Applicant* temp = front;
        cout << "\nCurrent line:\n";
        while (temp != NULL) {
            cout << "Applicant ID: " << temp->id << " | Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ApplicantQueue q;

    // Adding 7 applicants
    for (int i = 1; i <= 7; i++) {
        q.enqueue(new Applicant(i, 5.8 + i, 60 + i, 6.0, "Waiting"));
    }

    cout << "Initial Queue:\n";
    q.display();

    // The 2nd applicant leaves suddenly
    q.removeAtPosition(2);

    // The first applicant gives test
    q.dequeue();

    cout << "\nAfter changes:\n";
    q.display();

    return 0;
}

