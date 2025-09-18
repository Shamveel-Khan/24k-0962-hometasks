#include <iostream>
#include <string>
using namespace std;

class Ticket {
public:
    int id;
    string customer;
    string ride;
    Ticket* next;

    Ticket(int i, string c, string r) {
        id = i;
        customer = c;
        ride = r;
        next = nullptr;
    }
};

class BookingSystem {
private:
    Ticket* tail;

public:
    BookingSystem() {
        tail = nullptr;
    }

    void issueEnd(int id, string customer, string ride) {
        Ticket* newTicket = new Ticket(id, customer, ride);
        if (!tail) {
            tail = newTicket;
            tail->next = tail;
            return;
        }
        newTicket->next = tail->next;
        tail->next = newTicket;
        tail = newTicket;
    }

    void issueFront(int id, string customer, string ride) {
        Ticket* newTicket = new Ticket(id, customer, ride);
        if (!tail) {
            tail = newTicket;
            tail->next = tail;
            return;
        }
        newTicket->next = tail->next;
        tail->next = newTicket;
    }

    void cancelFront() {
        if (!tail) {
            cout << "No tickets\n";
            return;
        }
        Ticket* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
            return;
        }
        tail->next = head->next;
        delete head;
    }

    void cancelByID(int id) {
        if (!tail) {
            cout << "No tickets\n";
            return;
        }
        Ticket* curr = tail->next;
        Ticket* prev = tail;
        do {
            if (curr->id == id) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found\n";
    }

    void searchByID(int id) {
        if (!tail) {
            cout << "No tickets\n";
            return;
        }
        Ticket* curr = tail->next;
        do {
            if (curr->id == id) {
                cout << "Found: " << curr->id << " " << curr->customer << " " << curr->ride << endl;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found\n";
    }

    void display() {
        if (!tail) {
            cout << "No tickets\n";
            return;
        }
        Ticket* curr = tail->next;
        cout << "Tickets (circular order):\n";
        do {
            cout << curr->id << " " << curr->customer << " " << curr->ride << endl;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void countTickets() {
        if (!tail) {
            cout << "Total tickets: 0\n";
            return;
        }
        int count = 0;
        Ticket* curr = tail->next;
        do {
            count++;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Total tickets: " << count << endl;
    }

    void nextAfterID(int id) {
        if (!tail) {
            cout << "No tickets\n";
            return;
        }
        Ticket* curr = tail->next;
        do {
            if (curr->id == id) {
                cout << "Next Ticket: " << curr->next->id << " " << curr->next->customer << " " << curr->next->ride << endl;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found\n";
    }
};

int main() {
    BookingSystem system;
    system.issueEnd(1, "Usman", "RollerCoaster");
    system.issueEnd(2, "Abdullah", "FerrisWheel");
    system.issueEnd(3, "Kabeer", "BumperCars");
    system.display();
    cout << "---\n";

    system.issueFront(0, "VIP_Shamveel", "HauntedHouse");
    system.display();
    cout << "---\n";

    system.cancelByID(2);
    system.display();
    cout << "---\n";

    system.searchByID(3);
    system.cancelFront();
    system.display();
    cout << "---\n";

    system.countTickets();
    system.nextAfterID(3);

    return 0;
}