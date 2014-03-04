class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size(), M = T.size();
        int dp[N + 1][M + 1];
        for (int i = 0; i<= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i <= N; i++) dp[i][0] = 1;
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] += dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[N][M];
    }
};