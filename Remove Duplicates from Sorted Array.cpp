class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ret = 0, pre;
        for (int i = 0; i < n; i++) {
            if (i == 0 || A[i] != pre) {
                A[ret++] = A[i];
                pre = A[i];
            }
        }
        return ret;
    }
};