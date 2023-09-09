#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool valid_parenthesis(const string str) {
    stack<char> st;
    for (const char ch : str) {
        if (ch == '{' || ch == '[' || ch == '(')
            st.push(ch);
        else {
            if (st.empty()) return false;
            else if (st.top() == '{' && ch == '}' || st.top() == '[' && ch == ']' || st.top() == '(' && ch == ')') st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main() {
    string str; cin >> str;
    cout << valid_parenthesis(str) << endl;

    return 0;
}
