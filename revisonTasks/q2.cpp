// Reason: Shell Sort is chosen because it’s more efficient than Bubble Sort for moderately unsorted data.
// It allows far-apart elements to move faster toward their correct positions by using gaps, 
// reducing the total number of comparisons and swaps.

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

void shellSort(int* arr, int n) {
    int  num=0;
    for(int gap = n/2; gap>0;gap /=2) {
        for(int i=gap;i<n;i++) {
            int temp = arr[i];
            int j = i;

            while(j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }

            arr[j] = temp;
        }
        num++;

        cout<<"After pass# "<<num<<" :";
        printArr(arr, 7);
    }
}

int main() {
    int arr[] = {32, 25, 40, 12, 18, 50, 28};

    shellSort(arr, 7);
}