#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &m, int n) {
    return (row >= 0 && col >= 0 && row < n && col < n && m[row][col] == 1);
}

bool findFood(int row, int col, vector<vector<int>> &m, int n) {
    if (row == 2 && col == 2) {
        m[row][col] = 2;
        return true;
    }

    if (isSafe(row, col, m, n)) {
        m[row][col] = 2;  

        if (findFood(row + 1, col, m, n)) return true;
        if (findFood(row, col + 1, m, n)) return true;
        if (findFood(row - 1, col, m, n)) return true;
        if (findFood(row, col - 1, m, n)) return true;

        m[row][col] = 1;
        return false;
    }
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int n = 5;

    if (findFood(0, 0, maze, n)) {
        cout << "Rabbit's path to food:\n";
        for (auto row : maze) {
            for (auto cell : row) cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No path to food found!\n";
    }
}
