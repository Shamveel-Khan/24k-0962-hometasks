#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
   string data;
   Node *next;
   Node(string val) : data(val), next(nullptr) {}
};

class HashTable
{
private:
   vector<Node *> table;
   int buckets;

   int hashFunction(const string &key)
   {
      int sum = 0;
      for (char c : key)
         sum += int(c);
      return sum % buckets;
   }

public:
   HashTable(int size) : buckets(size)
   {
      table.resize(buckets, nullptr);
   }

   void insert(const string &key)
   {
      int index = hashFunction(key);
      Node *newNode = new Node(key);
      newNode->next = table[index];
      table[index] = newNode;
   }

   bool search(const string &key)
   {
      int index = hashFunction(key);
      Node *temp = table[index];
      while (temp != nullptr)
      {
         if (temp->data == key)
            return true;
         temp = temp->next;
      }
      return false;
   }

   void display()
   {
      cout << "Hash Table:\n";
      for (int i = 0; i < buckets; i++)
      {
         cout << "Bucket " << i << ": ";
         Node *temp = table[i];
         if (!temp)
         {
            cout << "NULL\n";
            continue;
         }
         while (temp != nullptr)
         {
            cout << temp->data << " -> ";
            temp = temp->next;
         }
         cout << "NULL\n";
      }
   }
};

int main()
{
   HashTable ht(10);

   ht.insert("apple");
   ht.insert("mango");
   ht.insert("apple");
   ht.insert("grapes");
   ht.insert("peach");
   ht.insert("banana");

   ht.display();

   cout << "\nSearching 'apple': "
        << (ht.search("apple") ? "Found" : "Not Found") << endl;

   cout << "Searching 'shamveel': "
        << (ht.search("shamveel") ? "Found" : "Not Found") << endl;

   return 0;
}