#include <iostream>
using namespace std;

class Exam
{
public:
    int *marks;

    Exam(int m)
    {
        marks = new int(m);
    }
    ~Exam()
    {
        delete marks;
    }
    void setMarks(int m)
    {
        *marks = m;
    }
    void show()
    {
        cout << *marks << endl;
    }
};

int main()
{
    Exam e1(50);
    Exam e2 = e1;

    cout << "Before Changes:\n";
    e1.show();
    e2.show();

    e2.setMarks(90);

    cout << "After Changing E2:\n";
    e1.show();
    e2.show();
}
