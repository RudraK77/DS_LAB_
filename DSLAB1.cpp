#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string exp = "231*+9-";
    stack<int> st;

    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    cout << "Result = " << st.top();

    return 0;
}