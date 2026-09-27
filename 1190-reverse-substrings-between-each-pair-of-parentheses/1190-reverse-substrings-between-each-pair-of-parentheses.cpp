class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.length();
        st.push("");
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(string(1, s[i]));
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                string temp = "";
                temp += s[i];
                int j = i + 1;
                while (j < n && (s[j] >= 'a' && s[j] <= 'z')) {
                    temp += s[j];
                    j++;
                }
                if (st.top() == "(") st.push(temp);
                else {
                    temp = st.top() + temp;
                    if (!st.empty()) st.pop();
                    st.push(temp);
                }
                i = j - 1;
            } else if (s[i] == ')') {
                if (!st.empty() && st.top() == "(") {
                    st.pop();
                } else {
                    string t = st.top();
                    if (!st.empty()) st.pop();
                    if (!st.empty()) st.pop();
                    reverse(t.begin(), t.end());
                    string temp = t;
                    if (!st.empty() && st.top() != "(") {
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.push(temp);
                }
            }
        }
        return st.top();
    }
};