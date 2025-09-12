#include <iostream>
using namespace std;

class jaggedArray {
public:
    int** data;
    int* rowSizes;
    int numRows;

    jaggedArray(int r, int* sizes) : numRows(r) {
        rowSizes = new int[numRows];
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            rowSizes[i] = sizes[i];
            data[i] = new int[rowSizes[i]];
            for (int j = 0; j < rowSizes[i]; ++j)
                data[i][j] = 0; 
        }
    }

    ~jaggedArray() {
        for (int i = 0; i < numRows; ++i)
            delete[] data[i];
        delete[] data;
        delete[] rowSizes;
    }

    void print() const {
        for (int i = 0; i < numRows; ++i) {
            cout << "Row #" << i << ": ";
            for (int j = 0; j < rowSizes[i]; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    int sum(int row) {
        int total = 0;
        for (int j = 0; j < rowSizes[row]; ++j)
            total += data[row][j];
        return total;
    }

    void store(int r, int c, int value) {
        if (r >= 0 && r < numRows && c >= 0 && c < rowSizes[r]) {
            data[r][c] = value;
        }
    }
};

int main() {
    int* arr = new int[3]{3, 1, 4};
    jaggedArray jagged(3, arr);
    jagged.print();
    cout<<endl;
    jagged.store(0, 0, 5);
    jagged.store(0, 1, 10);
    jagged.store(1, 2, 15);
    jagged.store(2, 0, 20);
    jagged.print();
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<=n;i++)
        cout<<"Sum of row "<<i<<" is "<<jagged.sum(i)<<endl;
    delete[] arr;
}