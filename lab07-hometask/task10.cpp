#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& a) {
    int m = a[0];
    for (int i = 1; i < a.size(); i++)
        if (a[i] > m) m = a[i];
    return m;
}

void countSort(vector<int>& a, int exp) {
    vector<int> out(a.size()), cnt(10, 0);
    for (int i = 0; i < a.size(); i++) cnt[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
    for (int i = a.size() - 1; i >= 0; i--) {
        int idx = (a[i] / exp) % 10;
        out[cnt[idx] - 1] = a[i];
        cnt[idx]--;
    }
    a = out;
}

void radixSort(vector<int>& a) {
    int m = getMax(a);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(a, exp);
        cout << "\nAfter sorting by digit " << exp << ": \n";
        for (int x : a) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<int> a = {54321, 12345, 98765, 67890, 13579, 24680, 11111, 22222, 33333, 44444,
                     55555, 66666, 77777, 88888, 99999, 11223, 22334, 33445, 44556, 55667};
    cout << "Before sorting:\n";
    for (int x : a) cout << x << " ";
    cout << endl << endl;
    radixSort(a);
    cout << "\nAfter full sorting:\n";
    for (int x : a) cout << x << " ";
}