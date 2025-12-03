#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable
{
private:
   string table[50];
   int size = 50;

   int sumASCII(const string &s)
   {
      int sum = 0;
      for (char c : s)
         sum += int(c);
      return sum;
   }

   int h1(const string &name)
   {
      return sumASCII(name) % size;
   }

   int h2(const string &name)
   {
      return 7 - (sumASCII(name) % 7);
   }

public:
   EmployeeHashTable()
   {
      for (int i = 0; i < size; i++)
         table[i] = "";
   }

   void Add_Employee(const string &name)
   {
      int primary = h1(name);
      int secondary = h2(name);

      if (table[primary] == "")
      {
         table[primary] = name;
         return;
      }

      for (int i = 1; i < size; i++)
      {
         int newIndex = (primary + i * secondary) % size;

         if (table[newIndex] == "")
         {
            table[newIndex] = name;
            return;
         }
      }

      cout << "Hash table is full. Cannot insert employee.\n";
   }

   void Search_Employee(const string &name)
   {
      int primary = h1(name);
      int secondary = h2(name);

      if (table[primary] == name)
      {
         cout << "Employee found at index " << primary << ": " << name << endl;
         return;
      }

      for (int i = 1; i < size; i++)
      {
         int newIndex = (primary + i * secondary) % size;
         if (table[newIndex] == name)
         {
            cout << "Employee found at index " << newIndex << ": " << name << endl;
            return;
         }
      }

      cout << "Employee not found in the directory.\n";
   }

   void Display_Table()
   {
      for (int i = 0; i < size; i++)
      {
         cout << i << ": ";
         if (table[i] == "")
            cout << "EMPTY";
         else
            cout << table[i];
         cout << endl;
      }
   }
};

int main()
{
   EmployeeHashTable ht;

   ht.Add_Employee("kabeer");
   ht.Add_Employee("shamveel");
   ht.Add_Employee("usman");
   ht.Add_Employee("andullah");
   ht.Add_Employee("harsh");

   cout << "\nEmployee Table:\n";
   ht.Display_Table();

   cout << "\nSearch Tests:\n";
   ht.Search_Employee("kabeer");
   ht.Search_Employee("sahil");

   return 0;
}