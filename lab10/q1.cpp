#include <vector>
#include <iostream>
using namespace std;
class Heap
{
public:
   int arr[100];
   int size;

   Heap()
   {
      size = 0;
   }

   void insert(int data)
   {
      size = size + 1;
      int index = size;

      arr[index] = data;

      while (index > 1)
      {
         int parent = index / 2;
         if (arr[parent] > arr[index])
         {
            swap(arr[parent], arr[index]);
            index = parent;
         }
         else
         {
            break;
         }
      }
   }

   void display()
   {
      for (int i = 1; i <= size; ++i)
      {
         cout << arr[i] << " ";
      }
      cout << endl;
   }
};

int main()
{
   Heap h;
   
   h.insert(1);
   h.insert(2);
   h.insert(3);
   h.insert(4);
   h.insert(5);

   h.display();
}