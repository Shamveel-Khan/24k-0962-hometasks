#include <iostream>
#include <stack>
using namespace std;

class call {
    string caller;
    int number;
public:
    call(string caller = "", int number = 0) : caller(caller), number(number) {}
    string getCaller() const { return caller; }
    int getNumber() const { return number; }
};

int main() {
    stack<call> st;
    int enter = 0;
    while (enter != -1) {
        cout << "\n1 to add call\n2 to see last call\n3 to remove last call\n4 to check if empty\n-1 to exit\n";
        cin >> enter;
        switch (enter) {
            case 1: {
                string name;
                int num;
                cout << "enter name of caller: ";
                cin >> name;
                cout << "enter number of caller: ";
                cin >> num;
                call myCall(name, num);
                st.push(myCall);
                break;
            }
            case 2: {
                if (!st.empty()) {
                    call topCall = st.top();
                    cout << "Last call from: " << topCall.getCaller() << " (" << topCall.getNumber() << ")\n";
                } else cout << "No calls in stack\n";
                break;
            }
            case 3: {
                if (!st.empty()) {
                    st.pop();
                    cout << "Last call removed\n";
                } else cout << "No calls to remove\n";
                break;
            }
            case 4: {
                if (st.empty()) cout << "Stack is empty\n";
                else cout << "Stack is not empty\n";
                break;
            }
            case -1:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
        }
    }
}
