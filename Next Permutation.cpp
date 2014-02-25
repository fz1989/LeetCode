class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size();
        if (N == 1) return;
        int pos;
        for (pos = N - 2; pos >= 0; pos--) {
            if (num[pos] < num[pos + 1]) {
                break;
            }
        }
        if (pos < 0)    {
            sort(num.begin(), num.end());
            return;
        }
        int end = N - 1;
        for (end; end >= 0; end--) {
            if (num[end] > num[pos])    break;
        }
        swap(num[end], num[pos]);
        reverse(num.begin() + pos + 1, num.end());
    }
};