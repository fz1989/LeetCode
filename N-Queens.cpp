class Solution {
private:
    int MOD;
    int N;
    vector<vector<string> > ret;
    string base;
    int calcPos(int num) {
        int ans = -1;
        while (num) {
            num >>= 1;
            ans++;
        }

        return ans;
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            base += '.';
        }
        int buf[n];
        MOD = (1 << n);
        N = n;
        solveNQueensHelper(0, 0, 0, 0, buf);
        return ret;
    }
    void solveNQueensHelper(int pren, int prel, int prer, int deep, int ans[]) {
        int now = pren | prel | prer;
        int next = now ^ (MOD - 1);
        if (deep == N) {
            vector <string> strAns;
            for (int i = 0; i < N; i++) {
                string tmp = base;
                tmp[calcPos(ans[i])] = 'Q';
                strAns.push_back(tmp);
            }
            ret.push_back(strAns);
            return;
        }

        while (next) {
            ans[deep] = next - (next & (next - 1));
            int npren = ans[deep] | pren;
            int nprel = ans[deep] | prel;
            int nprer = ans[deep] | prer;
            solveNQueensHelper(npren, (nprel << 1) % MOD, nprer >> 1, deep + 1, ans);
            next = next & (next - 1);
        }

    }
};