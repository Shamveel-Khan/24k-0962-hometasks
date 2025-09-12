#include <iostream>
using namespace std;

class Matrix {  
public:
    int rows, cols;
    int** data;

    Matrix(int r, int c, int fill = 0) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = fill;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void resize(int newRows, int newCols, int fill = 0) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newData[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                newData[i][j] = fill;
            }
        }
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
        data = newData;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; ++j)
                transposed[i][j] = data[j][i];
        }
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
        data = transposed;
        swap(rows, cols);
    }

    void addToOddIndices(int value) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if ((i * cols + j) % 2 == 1)
                    data[i][j] += value;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix mat(3, 3, 1);
    mat.print();
    cout << "After resizing to 4x4 with fill 5:" << endl;
    mat.resize(4, 4, 5);
    mat.print();
}