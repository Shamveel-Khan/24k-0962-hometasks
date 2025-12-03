#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(nullptr) {}
};

class Dictionary {
private:
    vector<Node*> table;
    int buckets = 100;

    int hashFunction(const string& w) {
        int sum = 0;
        for (char c : w) sum += int(c);
        return sum % buckets;
    }

public:
    Dictionary() {
        table.resize(buckets, nullptr);
    }

    void Add_Record(const string& w) {
        int index = hashFunction(w);
        Node* newNode = new Node(w);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void Word_Search(const string& w) {
        int index = hashFunction(w);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->word == w) {
                cout << "Word found: " << w << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Word '" << w << "' not found in dictionary.\n";
    }

    void Print_Dictionary() {
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            if (!temp) {
                cout << "NULL\n";
                continue;
            }
            while (temp != nullptr) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word;

    while (true) {
        cout << "\n1. Add Record\n2. Search Word\n3. Print Dictionary\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> word;
            dict.Add_Record(word);
        }
        else if (choice == 2) {
            cout << "Enter word to search: ";
            cin >> word;
            dict.Word_Search(word);
        }
        else if (choice == 3) {
            dict.Print_Dictionary();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}