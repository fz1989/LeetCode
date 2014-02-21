class Solution {
public:
    int search(int A[], int n, int target) {
        return searchHelper(A, 0, n - 1, target);
    }
    int searchHelper(int A[], int l, int r, int target) {
        if (l > r)  return -1;
        int mid = l + ((r - l) >> 1);
        if (A[mid] == target)   return mid;
        if (A[l] < A[mid]) {
            if (A[l] <= target && target < A[mid])   return searchHelper(A, l, mid - 1, target);
            else                                     return searchHelper(A, mid + 1, r, target);

        } else if (A[l] > A[mid]) {
            if (A[mid] < target && target <= A[r])   return searchHelper(A, mid + 1, r, target);
            else                                     return searchHelper(A, l, mid - 1, target);
        } else if (A[l] == A[mid]) {
            return searchHelper(A, mid + 1, r, target);
        }
        return -1;
    }
};