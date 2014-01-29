class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len_s1 = s1.size();
        int len_s2 = s2.size();
        int len_s3 = s3.size();
        if (len_s1 + len_s2 != len_s3)  return false;
        bool dp[len_s1 + 1][len_s2 + 1];
        dp[0][0] = true;
        for (int i = 1; i <= len_s1; i++) {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) & dp[i - 1][0]; 
        }
        for (int j = 1; j <= len_s2; j++) {
            dp[0][j] = (s2[j - 1] == s3[j - 1]) & dp[0][j - 1];
        }
        for (int i = 1; i <= len_s1; i++) {
            for (int j = 1; j <= len_s2; j++) {
                int cur = i + j - 1;
                dp[i][j] = false;
                if (s1[i - 1] == s3[cur]) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (s2[j - 1] == s3[cur]) {
                    dp[i][j] = dp[i][j - 1] | dp[i][j];
                }
            }
        }
        return dp[len_s1][len_s2];
    }
};
