class Solution {
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        ret.push_back(num);
        while (nextPermutation(num)) {
            ret.push_back(num);
        }
        return ret;
    }
    bool nextPermutation(vector<int> &num) {
        int N = num.size();
        if (N == 1) return false;
        int pos;
        for (pos = N - 2; pos >= 0; pos--) {
            if (num[pos] < num[pos + 1]) {
                break;
            }
        }
        if (pos < 0)    {
            sort(num.begin(), num.end());
            return false;
        }
        int end = N - 1;
        for (end; end >= 0; end--) {
            if (num[end] > num[pos])    break;
        }
        swap(num[end], num[pos]);
        reverse(num.begin() + pos + 1, num.end());
        return true;
    }
};