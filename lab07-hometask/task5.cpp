#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int cmp;

int partition(vector<int>& a, int l, int r, int pivot) {
    swap(a[pivot], a[r]);
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++) {
        cmp++;
        if (a[j] < p) swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(vector<int>& a, int l, int r, int type) {
    if (l >= r) return;
    int pivot;
    if (type == 1) pivot = l;
    else if (type == 2) pivot = l + rand() % (r - l + 1);
    else if (type == 3) pivot = (l + r) / 2;
    else {
        int mid = (l + r) / 2;
        vector<pair<int,int>> v = {{a[l],l},{a[mid],mid},{a[r],r}};
        sort(v.begin(), v.end());
        pivot = v[1].second;
    }
    int pi = partition(a, l, r, pivot);
    quicksort(a, l, pi - 1, type);
    quicksort(a, pi + 1, r, type);
}

int main() {
    srand(time(0));
    vector<int> base = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4}, a;
    for (int t = 1; t <= 4; t++) {
        a = base;
        cmp = 0;
        quicksort(a, 0, a.size() - 1, t);
        cout << "Pivot type " << t << " comparisons: " << cmp << endl;
    }
}