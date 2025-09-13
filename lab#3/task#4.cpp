#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data) : data(data), next(nullptr) {}
    node(int data, node *next) : data(data), next(next) {}
};

class linkedList
{
public:
    node *head;
    linkedList() : head(nullptr) {}
    linkedList(node *head) : head(head) {}

    static linkedList *fromVector(const vector<int> &arr)
    {
        if (arr.empty())
            return new linkedList();

        node *head = new node(arr[0]);
        node *curr = head;
        for (int i = 1; i < arr.size(); i++)
        {
            curr->next = new node(arr[i]);
            curr = curr->next;
        }
        return new linkedList(head);
    }

    void addToEnd(int val)
    {
        if (head == nullptr)
        {
            head = new node(val);
            return;
        }
        node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new node(val);
    }

    void addToStart(int val)
    {
        head = new node(val, head);
    }

    void print() const
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    vector<int> backToVector() const
    {
        vector<int> arr;
        node *temp = head;
        while (temp)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return arr;
    }

    void concatenateLinkedList(linkedList *list)
    {
        if (!head)
        {
            head = list->head;
            return;
        }
        node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = list->head;
    }

    // New function: sort the linked list using extra space
    void sortList()
    {
        if (!head || !head->next)
            return; // nothing to sort

        // Step 1: convert to vector
        vector<int> arr = backToVector();

        // Step 2: sort vector
        sort(arr.begin(), arr.end());

        // Step 3: rebuild linked list
        node *curr = head;
        for (int val : arr)
        {
            curr->data = val; // just overwrite instead of rebuilding nodes
            curr = curr->next;
        }
    }
    node* findMiddle() const {
        if (!head) return nullptr;

        node* slow = head;
        node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; 
    }

};

int main()
{
    vector<int> arr = {1, 19, 5, 37, 9};
    linkedList *list = linkedList::fromVector(arr);

    cout << "Initial list before sorting: \n";
    list->print();

    list->sortList();

    cout << "\nAfter sorting: \n";
    list->print();

    vector<int> arr2 = {6, 2, 4, 0};
    linkedList *list2 = linkedList::fromVector(arr2);

    cout << "\nNew List: \n";
    list2->print();

    list->concatenateLinkedList(list2);

    cout << "\nAfter concatenating new list: \n";
    list->print();

    node* middle = list->findMiddle();
    if (middle)
        cout << "Middle element: " << middle->data << endl;
    else
        cout << "List is empty!" << endl;
    return 0;
}
