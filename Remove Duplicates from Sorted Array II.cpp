class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ret = 0, cnt = 0, key = -1;
        for (int i = 0; i < n; i++) {
            if (key == A[i]) {
                cnt++;
                if (cnt <= 2) {
                    A[ret++] = A[i];
                } 
            } else {
                A[ret++] = A[i];
                key = A[i];
                cnt = 1;
            }
        }
        return ret;
    }
};