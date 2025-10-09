// if no safe route exists, backtracking reverses each
//  move (undoes the path) until all options are tried.
//   When no valid path remains, the function returns false.
// The line return false; inside solveMaze() is responsible 
// for this behavior.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &m, int n) {
    if(row>=0 && col>= 0 && row<n && col<n && m[row][col]==1) {
        return true;
    }
    return false;
}

bool solveMaze(int row, int col, vector<vector<int>> &m, int n) {
    if(row == n-1 && col == n-1) {
        m[row][col] =2;
        return true;
    }

    if(isSafe(row,col,m,n)) {
        m[row][col] =2;
        if(solveMaze(row+1,col,m,n)) return true;
        if(solveMaze(row-1,col,m,n)) return true;
        if(solveMaze(row,col+1,m,n)) return true;
        if(solveMaze(row,col-1,m,n)) return true;
        m[row][col] = 1;
        return false;
    }
    return false;
}

int main() {
    vector<vector<int>> maze = {
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 1, 0, 1},
    {0, 1, 1, 1}
    };

    if(solveMaze(0, 0, maze, 4)) {
        for(auto row : maze) {
            for(auto cell : row) {
                cout<<cell<<" ";
            }
            cout<<endl;
        }
    }
}