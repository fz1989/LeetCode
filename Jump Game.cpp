class Solution {
public:
    bool canJump(int A[], int n) {
        int start = 0, end = A[0];
        for (int i = 1; i < n; i++) {
            if (i> end) return false;
            else        end = max(end, i + A[i]);
        }
        return end >= n - 1;
    }
};