class Solution {
public:
    double pow(double x, int n) {
        double ret = 1.0;
        long long N = n;
        if (n < 0)  N = -N, x = 1.0 / x;
        while (N) {
            if (N & 1) ret *= x;
            x *= x;
            N /= 2;
        }
        return ret;
    }
};