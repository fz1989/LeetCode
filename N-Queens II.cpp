class Solution {
private:
    int MOD;
    int sum;
    int N;
public:
    int totalNQueens(int n) {
        N = n;
        MOD = (1 << n);
        sum = 0;
        totalNQueensHelper(0, 0, 0, 0);
        return sum;
    }
    void totalNQueensHelper(int pre, int prel, int prer, int deep) {
        int now = pre | prel | prer;
        int next = (now) ^ (MOD - 1);
        if (deep == N) {
            sum++;
            return;
        }

        while (next) {
            int tmp = next - (next & (next - 1));
            int nnext = tmp | pre;
            int nprel = tmp | prel;
            int nprer = tmp | prer;
            totalNQueensHelper(nnext, nprel >> 1, (nprer << 1) % MOD, deep + 1);
            next = (next & (next - 1));
        }
    }
};