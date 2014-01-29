class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        for (int i = 0; i < n; i++) {
            vector <int> tmp(n, 0);
            ret.push_back(tmp);
        }
        int dirx[4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0};
        int x = 0, y = 0, dir = 0;
        for (int i = 1; i <= n * n ; i++) {
            ret[x][y] = i;
            int nextx = x + dirx[dir];
            int nexty = y + diry[dir];
            if (nextx >= n || nextx < 0 || nexty >= n || nexty < 0 || ret[nextx][nexty]) {
                dir = (dir + 1) % 4;
                nextx = x + dirx[dir];
                nexty = y + diry[dir];
            }
            x = nextx, y = nexty;
        }
        return ret;
    }
};
