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

    void sortList()
    {
        if (!head || !head->next)
            return;
        vector<int> arr = backToVector();

        sort(arr.begin(), arr.end());

        node *curr = head;
        for (int val : arr)
        {
            curr->data = val;
            curr = curr->next;
        }
    }
    node *findMiddle() const
    {
        if (!head)
            return nullptr;

        node *slow = head;
        node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

   void mergeSortedList(linkedList *list)
    {
        node *temp2 = list->head;

        while (temp2 && temp2->data < head->data)
        {
            node *newNode = new node(temp2->data, head);
            head = newNode;           
            temp2 = temp2->next;      
        }

        node *temp = head;
        while (temp2)
        {
            if (temp->next == nullptr || temp->next->data >= temp2->data)
            {
                node *newNode = new node(temp2->data, temp->next);
                temp->next = newNode;

                temp2 = temp2->next;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
void removeDuplicates()
{
        if (!head || !head->next) return;

        vector<int> arr = backToVector();

        sort(arr.begin(), arr.end());   
        arr.erase(unique(arr.begin(), arr.end()), arr.end()); 

        node* curr = head;
        for (int val : arr) {
            curr->data = val;
            if (!curr->next && &val != &arr.back()) {
                curr->next = new node(0);
            }
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < arr.size() - 1; i++) curr = curr->next;
        curr->next = nullptr;
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

    vector<int> arr2 = {6, 2, 4, 5, 0};
    linkedList *list2 = linkedList::fromVector(arr2);

    cout << "\nNew List: \n";
    list2->print();

    list->concatenateLinkedList(list2);

    cout << "\nAfter concatenating new list: \n";
    list->print();

    node *middle = list->findMiddle();
    if (middle)
        cout << "Middle element: " << middle->data << endl;
    else
        cout << "List is empty!" << endl;

    list2->sortList();
    list2->print();

    list->mergeSortedList(list2);
    list->print();

    list->removeDuplicates();
    list->print();
}
