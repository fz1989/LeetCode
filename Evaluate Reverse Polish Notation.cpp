class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int len = tokens.size();
        for (int i = 0; i < len; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(evalRPNHelper(op1, op2, tokens[i]));
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        int ret = st.top();
        st.pop();
        return ret;
    }
    int evalRPNHelper(int op1, int op2, string op) {
        if (op == "+")  return op1 + op2;
        if (op == "-")  return op1 - op2;
        if (op == "*")  return op1 * op2;
        if (op == "/")  return op1 / op2;
    }
};