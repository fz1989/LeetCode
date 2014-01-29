class Solution {
public:
    void sortColors(int A[], int n) {
        int cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 0; i < n; i++) {
            cnt[A[i]]++;
        }
        int pi = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                A[pi++] = i;
            }
        }
    }
};
