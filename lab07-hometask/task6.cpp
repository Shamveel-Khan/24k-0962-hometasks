#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    int salary;
    Employee(string n, int i, int s) {
        name = n; id = i; salary = s;
    }
};

void merge(vector<Employee>& a, int l, int m, int r) {
    vector<Employee> L(a.begin() + l, a.begin() + m + 1);
    vector<Employee> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i].salary >= R[j].salary) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}

void mergesort(vector<Employee>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    vector<Employee> e = {
        {"Ali",1,50000},{"Shamveel",2,75000},{"Ahmed",3,65000},
        {"amjad",4,90000},{"usman",5,80000},{"Usman",6,55000},
        {"sahil",7,72000},{"abdullah",8,88000},{"Fahad",9,60000},
        {"Ahmed",10,95000},{"harsh",11,70000},{"Hassan",12,77000}
    };
    mergesort(e, 0, e.size() - 1);
    cout << "Top 3 highest-paid employees:\n";
    for (int i = 0; i < 3; i++)
        cout << e[i].name << " " << e[i].id << " " << e[i].salary << endl;
}