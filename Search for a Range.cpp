class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        ret.push_back(lowerSearch(A, n, target, true));
        ret.push_back(lowerSearch(A, n, target, false));
        return ret;
    }
    int lowerSearch(int A[], int n, int target, bool lower) {
        if (target < A[0] || target > A[n - 1]) return -1;
        int l = 0, r = n - 1;
        int ret = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (A[mid] == target) {
                ret = mid;
                if (lower)  r = mid - 1;
                else        l = mid + 1;
            } else if (A[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }
};