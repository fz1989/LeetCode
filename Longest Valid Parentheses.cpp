class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int last = -1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (st.empty()) last = i;
                else {
                    st.pop();
                    if (st.empty()) {
                        ret = max(ret, i - last);
                    } else {
                        ret = max(ret, i - st.top());
                    }
                }
            }
        }
        return ret;
    }
};