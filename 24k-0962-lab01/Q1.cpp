#include <iostream>
#include <string>
using namespace std;

class ResearchPaper
{
public:
    string *authors;
    int count;

    ResearchPaper(int n)
    {
        count = n;
        authors = new string[count];
        for (int i = 0; i < count; i++)
        {
            string name;
            cout << "Enter the name#" << i + 1 << ": ";
            cin >> name;
            authors[i] = name;
        }
    }
    ~ResearchPaper()
    {
        delete[] authors;
    }
    ResearchPaper(const ResearchPaper &r)
    {
        count = r.count;
        authors = new string[count];
        for (int i = 0; i < count; i++)
        {
            authors[i] = r.authors[i];
        }
    }
    ResearchPaper &operator=(const ResearchPaper &r)
    {
        if (this != &r)
        {
            delete[] authors;
            count = r.count;
            authors = new string[count];
            for (int i = 0; i < count; i++)
            {
                authors[i] = r.authors[i];
            }
        }
        return *this;
    }
    void show()
    {
        for (int i = 0; i < count; i++)
        {
            cout << authors[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ResearchPaper r1(2);
    ResearchPaper r2 = r1;
    cout<<"\nBefore Changes: \n";
    r2.show();
    r1.show();
    r2.authors[0] = "name3";
    r2.authors[1] = "name4";
    cout << "\nAfter Changes in R2: \n";
    r2.show();
    r1.show();
}