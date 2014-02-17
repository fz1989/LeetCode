class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector <vector<int>> ret;
        int n = S.size();
        for (int i = 0; i < (1 << n); i++) {
            vector <int> tmp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) tmp.push_back(S[j]);
            }
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};