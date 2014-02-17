class Solution {
public:
    int trap(int A[], int n) {
        int lmax[n], rmax[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) lmax[i] = A[i];
            else {
                lmax[i] = max(A[i - 1], lmax[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) rmax[i] = A[i];
            else {
                rmax[i] = max(A[i + 1], rmax[i + 1]);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += max(0, min(rmax[i], lmax[i]) - A[i]);
        }
        return ret;
    }
};