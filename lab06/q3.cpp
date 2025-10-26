#include <iostream>
#include <stack>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

void addFront(Node*& head, string url) {
    Node* newNode = new Node(url);
    newNode->next = head;
    head = newNode;
}

void removeFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    stack<string> history;
    Node* head = NULL;

    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (string s : sites) {
        addFront(head, s);
        history.push(s);
    }

    history.pop();
    removeFront(head);
    history.pop();
    removeFront(head);

    cout << "Current page: " << history.top() << endl;
    cout << "Linked list from most recent:\n";
    for (Node* curr = head; curr; curr = curr->next)
        cout << curr->url << " ";
}
