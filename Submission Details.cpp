class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ret = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (i == 0 || sum > ret)
                ret = sum;
            if (sum < 0)
                sum = 0;
        }
        return ret;
    }
};