#include <iostream>
using namespace std;

class Box
{
public:
    int *volume;

    Box()
    {
        volume = new int(0);
    }
    Box(int v)
    {
        volume = new int(v);
    }
    Box(const Box &b)
    {
        volume = new int(*b.volume);
    }
    ~Box()
    {
        delete volume;
    }
    void setVolume(int v)
    {
        *volume = v;
    }
    void show()
    {
        cout << *volume << endl;
    }
};

int main()
{
    Box b1(10);
    Box b2 = b1;
    cout << "Before Changes:\n";
    b1.show();
    b2.show();

    b2.setVolume(25);

    cout << "After Changing B2:\n";
    b1.show();
    b2.show();
}