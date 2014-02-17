class Solution {
public:
    bool isValid(string s) {
        stack <char> St;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            switch (ch) {
                case '(':;
                case '[':;
                case '{':;
                    St.push(ch);
                    break;
                case ')':
                    if (St.empty() || St.top() != '(')    return false;
                    else {
                        St.pop();
                        break;
                    }
                case ']':
                    if (St.empty() || St.top() != '[')    return false;
                    else {
                        St.pop();
                        break;
                    }
                case '}':
                    if (St.empty() || St.top() != '{')    return false;
                    else {
                        St.pop();
                        break;
                    }
            }
        }
        if (St.empty())  return true;
        else            return false;
    }
};