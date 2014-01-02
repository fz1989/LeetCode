class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        int N = num.size();
        helper(0, N, ret, num);
        return ret;
    }
    void helper(int start, int n, vector<vector<int> > &ret, vector<int> &num) {
        if (n == 1) {
            ret.push_back(num);
        }
        for (int i = start; i < start + n; i++) {
            swap(num[start], num[i]);
            helper(start + 1, n - 1, ret, num);
            swap(num[start], num[i]);
        }
    }
};