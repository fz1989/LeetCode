class Solution {
public:
    int jump(int A[], int n) {
        int start = 0, end = A[0];
        int ret = 0;
        for (int i = 1; i < n; ) {
            int next_end = 0;
            while (i < n && i <= end) {
                next_end = max(next_end, A[i] + i);
                i++;
            }
            ret++;
            end = next_end;
            if (end >= n - 1)   ret + 1;
        }
        return ret;
    }
};