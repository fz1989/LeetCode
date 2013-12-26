class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i = 0; i < m; i++) {
            A[n + m -  1 - i] = A[m - 1 - i];
        }
        int pa = n, pb = 0, ret = 0;
        while (pa < m + n && pb < n) {
            if (A[pa] < B[pb])
                A[ret++] = A[pa++];
            else 
                A[ret++] = B[pb++];
        }
        for (int i = pa; i < m + n; i++) {
            A[ret++] = A[i];
        }
        for (int j = pb; j < n; j++) {
            A[ret++] = B[j];
        }
    }
};