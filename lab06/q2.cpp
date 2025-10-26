#include <iostream>
#include <stack>
using namespace std;

int main() {
    string input;
    cout << "Enter postfix expression (no spaces): ";
    cin >> input;

    stack<int> st;

    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            st.push(input[i] - '0');
        } else {
            int oper2 = st.top(); st.pop();
            int oper1 = st.top(); st.pop();

            switch (input[i]) {
                case '+': st.push(oper1 + oper2); break;
                case '-': st.push(oper1 - oper2); break;
                case '*': st.push(oper1 * oper2); break;
                case '/': st.push(oper1 / oper2); break;
            }
        }
    }

    cout << "The answer is: " << st.top() << endl;
    return 0;
}
