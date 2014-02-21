class Solution {
public:
    bool search(int A[], int n, int target) {
        return searchHelper(A, 0, n - 1, target);
    }
    bool searchHelper(int A[], int l, int r, int target) {
        if (l > r)  return false;
        int mid = l + ((r - l) >> 1);
        if (A[mid] == target)   return true;
        if (A[l] < A[mid]) {
            if (A[l] <= target && target < A[mid])   return searchHelper(A, l, mid - 1, target);
            else                                     return searchHelper(A, mid + 1, r, target);

        } else if (A[l] > A[mid]) {
            if (A[mid] < target && target <= A[r])   return searchHelper(A, mid + 1, r, target);
            else                                     return searchHelper(A, l, mid - 1, target);
        }
        return searchHelper(A, mid + 1, r, target) | searchHelper(A, l, mid - 1, target);
    }
};