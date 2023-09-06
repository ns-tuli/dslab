#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;




   bool isValid(const string& s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                return false;
            }           char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}


int main() {
    string s;
    cin>>s;
    if(isValid(s))
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }





    return 0;
}

