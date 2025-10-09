// Shell Sort is more efficient for this case because the list of book IDs is not nearly sorted.
// Insertion Sort compares adjacent elements and moves small elements one position at a time, causing many shifts when the data is unsorted.
// In contrast, Shell Sort starts by comparing elements far apart (using large gaps), moving them closer to their correct positions quickly.
// As the gap decreases, fewer shifts are needed, making the sorting process faster overall.
// Therefore, for this random set of book IDs, Shell Sort performs significantly fewer comparisons and swaps than Insertion Sort, making it more efficient.

#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void shellSort(int *arr, int n)
{
    int num=0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        num++;
        cout<<"After pass# "<<num<<" :";
        printArr(arr, 6);
    }
}

int main() {
    int arr[] = {205, 102, 310, 450, 120, 90};

    shellSort(arr, 6);
}