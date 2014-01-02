class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int N = grid.size();
        int M = grid[0].size();
        for (int i = 1; i < M; i++) {
            grid[0][i] += grid[0][i - 1]; 
        }
        for (int i = 1; i < N; i++) {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < M; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[N - 1][M - 1];
    }
};