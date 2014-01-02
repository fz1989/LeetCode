class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        if (matrix[0][0] > target 
            || matrix[N - 1][M - 1] < target)
            return false;
        int l = 0, r = N - 1, mid, row;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (matrix[mid][0] <= target) {
                row = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0, r = M -1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (matrix[row][mid] < target) {
                l = mid + 1;
            } else if (matrix[row][mid] > target) {
                r = mid -1;
            } else return true;
        }
        return false;
    }
};