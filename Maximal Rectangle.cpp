class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int N = matrix.size();
        if (N == 0) return 0;
        int M = matrix[0].size();
        if (M == 0) return 0;
        int left[N][M], right[N][M], lmost, rmost,up[N][M], ret = 0;
        for (int i = 0; i < N; i++) {
            lmost = -1;
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == '1') {
                    up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                    left[i][j] = i == 0 ? lmost + 1: max(left[i - 1][j], lmost + 1);
                } else {
                    left[i][j] = up[i][j] = 0;
                    lmost = j;
                }
            }
            rmost = M;
            for (int j = M - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[i][j] = i == 0 ? rmost - 1: min(right[i - 1][j], rmost - 1);
                    ret = max(ret, up[i][j] * (right[i][j] - left[i][j] + 1));
                } else {
                    right[i][j] = M;
                    rmost = j;
                }
            }
        }
        return ret;
        
    }
};
