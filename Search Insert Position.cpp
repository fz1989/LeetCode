class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n - 1, ret;
        if (A[0] > target)  return 0;
        if (A[n - 1] < target)  return n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) {
                l = mid + 1;
            } else {
                ret = mid;
                r = mid - 1;
            }
        }
        return ret;
    }
};