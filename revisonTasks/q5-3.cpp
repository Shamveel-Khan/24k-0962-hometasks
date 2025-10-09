#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &m, int n)
{
    return (row >= 0 && col >= 0 && row < n && col < n && m[row][col] == 1);
}

bool findFoodForCat(int row, int col, vector<vector<int>> &m, int n)
{
    if (row == 2 && col == 2)
    {
        m[row][col] = 3;
        return true;
    }

    if (isSafe(row, col, m, n))
    {
        m[row][col] = 3;

        if (findFoodForCat(row + 1, col, m, n))
            return true;
        if (findFoodForCat(row, col + 1, m, n))
            return true;
        if (findFoodForCat(row - 1, col, m, n))
            return true;
        if (findFoodForCat(row, col - 1, m, n))
            return true;

        m[row][col] = 1;
        return false;
    }
    return false;
}

bool findFoodForRabbit(int row, int col, vector<vector<int>> &m, int n)
{
    if (row == 2 && col == 2)
    {
        m[row][col] = 2;
        return true;
    }

    if (isSafe(row, col, m, n))
    {
        m[row][col] = 2;

        if (findFoodForRabbit(row + 1, col, m, n))
            return true;
        if (findFoodForRabbit(row, col + 1, m, n))
            return true;
        if (findFoodForRabbit(row - 1, col, m, n))
            return true;
        if (findFoodForRabbit(row, col - 1, m, n))
            return true;

        m[row][col] = 1;
        return false;
    }
    return false;
}

void printMaze(const vector<vector<int>> &maze)
{
    for (auto &row : maze)
    {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> maze = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}};

    int n = 5;

    vector<vector<int>> rabbitMaze = maze;
    vector<vector<int>> catMaze = maze;

    findFoodForRabbit(0, 0, rabbitMaze, n);
    findFoodForCat(4, 4, catMaze, n);

    cout << "Rabbit Path (2):\n";
    printMaze(rabbitMaze);
    cout << "\nCat Path (3):\n";
    printMaze(catMaze);

    cout << "\nCombined Maze (9 = intersection):\n";
    vector<vector<int>> combined = maze;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rabbitMaze[i][j] == 2 && catMaze[i][j] == 3)
                combined[i][j] = 9;
            else if (rabbitMaze[i][j] == 2)
                combined[i][j] = 2;
            else if (catMaze[i][j] == 3)
                combined[i][j] = 3;
        }
    }

    printMaze(combined);
}