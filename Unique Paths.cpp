class Solution {
public:
    int C[200][200];
    int calc(int m, int n) {
        if (C[m][n] != -1)  return C[m][n];
        if (n == 0 || m == n) return C[m][n] = 1;
        C[m][n] = calc(m - 1, n) + calc(m - 1, n - 1);
        return C[m][n];
    }
    void init() {
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                C[i][j] = -1;
            }
        }
    }
    int uniquePaths(int m, int n) {
        init();
        return calc(m + n - 2, m - 1);    
    }
};