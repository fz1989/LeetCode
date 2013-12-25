class Solution {
public:
    int reverse(int x) {
        int adder = 1;
        if (x < 0) {
            adder = -1;
        }
        x *= adder;
        int ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret * adder;
    }
};