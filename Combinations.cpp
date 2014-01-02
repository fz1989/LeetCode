class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        int A[n + 1];
        helper(0, n, 0, k, ret, A);
        return ret;
    }
    void helper(int now, int N, int pos, int K, vector<vector<int> > &ret, int A[]) {
        if (pos == K) {
            vector<int> tmp;
            for (int i = 0; i < K; i++) {
                tmp.push_back(A[i]);
            }
            ret.push_back(tmp);
            return;
        }
        if (now >= N)   return;
        A[pos] = now + 1;
        helper(now + 1, N, pos + 1, K, ret, A);
        helper(now + 1, N, pos, K, ret, A);
    }
};