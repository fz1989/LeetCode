class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstR = false, firstC = false;
        int N = matrix.size();
        if (N == 0) return;
        int M = matrix[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i == 0) firstR = true;
                    if (j == 0) firstC = true;
                }
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstR) {
            for (int i = 0; i < M; i++) {
                matrix[0][i] = 0;
            }
        }
        if (firstC) {
            for (int i = 0; i < N; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};