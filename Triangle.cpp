class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int N = triangle.size();
        int dp[N];
        for (int i = 0; i < N; i++) {
            dp[i] = 0x7fffffff;
        }
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j > 0; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        int ret = 0x7fffffff;
        for (int i = 0; i < N; i++) {
            ret = min(ret, dp[i]);
        }
        return ret;
        
    }
};