#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void countingSort(int data[], int size, int place) {
    int sorted[size];
    int freq[10] = {0};

    for (int i = 0; i < size; i++)
        freq[(data[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        freq[i] += freq[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int digit = (data[i] / place) % 10;
        sorted[freq[digit] - 1] = data[i];
        freq[digit]--;
    }

    for (int i = 0; i < size; i++)
        data[i] = sorted[i];
}

void radixSort(int data[], int size) {
    int maxNum = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > maxNum)
            maxNum = data[i];

    for (int place = 1; maxNum / place > 0; place *= 10)
        countingSort(data, size, place);
}

int main() {
    srand(time(0));
    int marks[50];
    for (int i = 0; i < 50; i++)
        marks[i] = rand() % 101;

    cout << "Original Marks:\n";
    for (int i = 0; i < 50; i++)
        cout << marks[i] << " ";
    cout << "\n\n";

    radixSort(marks, 50);

    cout << "Marks with Ranks (Highest = Rank 1):\n";
    int position = 1;
    for (int i = 49; i >= 0; i--)
        cout << "Rank " << position++ << ": " << marks[i] << endl;

    return 0;
}