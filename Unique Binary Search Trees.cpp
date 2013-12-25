class Solution {
public:
    int numTrees(int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++) {
            ret = ret * (4 * i - 2) / (i + 1);
        }
        return ret;
    }
};