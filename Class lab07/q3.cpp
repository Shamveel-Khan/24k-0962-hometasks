#include <iostream>
#include <string>
using namespace std;

class Item
{
    string title;
    double cost;
    string details;
    bool inStock;

public:
    Item(string t, double c, string det, bool s) : title(t), cost(c), details(det), inStock(s) {}

    double getCost() const { return cost; }
    string getTitle() const { return title; }
    string getDetails() const { return details; }
    bool isInStock() const { return inStock; }
};

void exchange(Item &x, Item &y)
{
    Item temp = x;
    x = y;
    y = temp;
}

int divide(Item list[], int start, int end)
{
    double pivotCost = list[end].getCost();
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (list[j].getCost() < pivotCost)
        {
            i++;
            exchange(list[i], list[j]);
        }
    }
    exchange(list[i + 1], list[end]);
    return i + 1;
}

void sortQuick(Item list[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = divide(list, start, end);
        sortQuick(list, start, pivotIndex - 1);
        sortQuick(list, pivotIndex + 1, end);
    }
}

void showItems(Item list[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Item Title: " << list[i].getTitle() << endl;
        cout << "Cost: $" << list[i].getCost() << endl;
        cout << "Details: " << list[i].getDetails() << endl;
        cout << "Stock: " << (list[i].isInStock() ? "Available" : "Unavailable") << endl;
        cout << endl;
    }
}

int main()
{
    Item inventory[3] = {
        Item("Lays", 1000, "xys", true),
        Item("Cakes", 540, "etry", true),
        Item("Biscuits", 3400, "uytuy", false)};

    sortQuick(inventory, 0, 2);

    cout << "Sorted Item List by Cost:" << endl;
    showItems(inventory, 3);
}
