#include <vector>
#include <iostream>
using namespace std;

class Heap
{

public:
   int arr[10];
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
         if (arr[parent] < arr[index])
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

   void Remove()
   {

      int index = size;
      arr[1] = index;
      size--;

      while (index <= size)
      {
         int left = 2 * index, right = 2 * index + 1;
         if (left < size && right < size && arr[left] > arr[index] && arr[right] > arr[index])
         {

            if (arr[left] > arr[right])
            {
               swap(arr[left], arr[index]);
               index = left;
            }
            else
            {
               swap(arr[right], arr[index]);
               index = right;
            }
         }
         else if (left < size && arr[left] > arr[index])
         {
            swap(arr[left], arr[index]);
            index = left;
         }
         else if (right < size && arr[right] > arr[index])
         {
            swap(arr[right], arr[index]);
            index = right;
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

   cout << "Adding patient severity 10";
   h.insert(10);
   cout << endl;
   cout << "Heap after inserting 10 ";
   h.display();
   cout << endl;

   cout << "Removing highest severity patient";
   h.Remove();
   cout << endl;
   cout << "Heap after removal: ";
   h.display();

   return 0;
}
