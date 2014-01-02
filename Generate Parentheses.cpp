class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ret;
        helper(0, 0, n, string(""), ret);
        return ret;
    }
    void helper(int left ,int right, int total, string now, vector <string> &ret) {
        if (left == total) {
            for (int i = 0; i < total - right; i++) {
                now += ')';
            }
            ret.push_back(now);
            return;
        }
        helper(left + 1, right, total, now + "(", ret);
        if (left > right)   helper(left, right + 1, total, now + ")", ret);
    }
};