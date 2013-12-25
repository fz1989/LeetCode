class Solution {
public:
    int climbStairs(int n) {
        int fir = 1, sec = 1, tmp;
        for (int i = 2; i <= n; i++) {
            tmp = fir + sec;
            fir = sec;
            sec = tmp;
        }
        return sec;
    }
};