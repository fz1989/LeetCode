class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        long long n = x > 0? x : (-x), tmp = n;
        long long num = 0;
        while (tmp) {
            num = num * 10 + tmp % 10;
            tmp /= 10;
        }
        return n == num;
    }
};
