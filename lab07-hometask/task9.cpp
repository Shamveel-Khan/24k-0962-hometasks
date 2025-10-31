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
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, exp);
}

int main() {
    vector<int> a = {2500, 1500, 1500, 3200, 450, 1200, 3000, 2500, 900};
    radixSort(a);
    cout << "Sorted transactions:\n";
    for (int x : a) cout << x << " ";
}