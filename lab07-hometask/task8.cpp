#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int getMax(vector<int>& a) {
    int mx = a[0];
    for (int i = 1; i < a.size(); i++)
        if (a[i] > mx) mx = a[i];
    return mx;
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
    for (int i = 0; i < a.size(); i++) a[i] = out[i];
}

void radixSort(vector<int>& a) {
    int m = getMax(a);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, exp);
}

int main() {
    srand(time(0));
    vector<int> a(50);
    for (int i = 0; i < 50; i++) a[i] = rand() % 101;
    radixSort(a);
    cout << "Scores (ascending) and ranks:\n";
    for (int i = 0; i < 50; i++)
        cout << "Rank " << i + 1 << ": " << a[i] << endl;
}