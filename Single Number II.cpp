class Solution {
public:
    int singleNumber(int A[], int n) {
        int num[32];
        for (int i = 0; i < 32; i++)    num[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (A[i] & (1 << j))   num[j] = (num[j] + 1) % 3;
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (num[i]) ret |= (1 << i);
        }
        return ret;
    }
};