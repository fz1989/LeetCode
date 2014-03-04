class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int l = j + 1, r = N - 1;
                while (l < r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum < target) l++;
                    if (sum > target) r--;
                    if (sum == target) {
                        vector <int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        ret.push_back(tmp);
                        if (l + 1 < r && num[l] == num[l + 1]) l++;
                        else if (r - 1 > l && num[r] == num[r - 1]) r--;
                        else {
                            r--;
                        }
                    }
                }
            }
        }
        sort(ret.begin(), ret.end());
        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
        return ret;
    }
};