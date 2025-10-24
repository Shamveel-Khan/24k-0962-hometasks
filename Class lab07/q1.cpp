#include <iostream>
#include <string>
using namespace std;

struct Element {
    string student;
    int marks;
    Element* link;
    Element(string s, int m) : student(s), marks(m), link(nullptr) {}
};

class ChainList {
public:
    Element* start;
    ChainList() : start(nullptr) {}

    void insert(string student, int marks) {
        Element* newElem = new Element(student, marks);
        if (!start) {
            start = newElem;
            return;
        }
        Element* mover = start;
        while (mover->link)
            mover = mover->link;
        mover->link = newElem;
    }

    int getHighestMarks() {
        int highest = 0;
        Element* mover = start;
        while (mover) {
            if (mover->marks > highest)
                highest = mover->marks;
            mover = mover->link;
        }
        return highest;
    }

    void sortRadix() {
        int place = 1;
        int highest = getHighestMarks();
        while (highest / place > 0) {
            sortByPlace(place);
            place *= 10;
        }
    }

    void sortByPlace(int place) {
        Element* bins[10] = {nullptr};
        Element* tails[10] = {nullptr};
        Element* mover = start;

        while (mover) {
            int digit = (mover->marks / place) % 10;
            Element* nextElem = mover->link;
            mover->link = nullptr;

            if (!bins[digit]) {
                bins[digit] = tails[digit] = mover;
            } else {
                tails[digit]->link = mover;
                tails[digit] = mover;
            }
            mover = nextElem;
        }

        Element* newStart = nullptr;
        Element* newEnd = nullptr;
        for (int i = 0; i < 10; i++) {
            if (bins[i]) {
                if (!newStart) {
                    newStart = bins[i];
                    newEnd = tails[i];
                } else {
                    newEnd->link = bins[i];
                    newEnd = tails[i];
                }
            }
        }
        start = newStart;
    }

    void display() {
        Element* mover = start;
        while (mover) {
            cout << mover->student << " " << mover->marks << endl;
            mover = mover->link;
        }
    }
};

int main() {
    ChainList students;
    int total;
    cout << "Enter number of students: ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        string student;
        int marks;
        cout << "Enter name and marks of student " << i + 1 << ": ";
        cin >> student >> marks;
        students.insert(student, marks);
    }

    cout << "\nOriginal list:\n";
    students.display();

    students.sortRadix();

    cout << "\nSorted list:\n";
    students.display();

    return 0;
}
