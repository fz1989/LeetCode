class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int N = S.size();
        vector<vector<int> > ret;
        for (int i = 0; i < (1 << N); i++) {
            vector <int> tmp;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) tmp.push_back(S[j]);
            }
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
        sort(ret.begin(), ret.end());
        int len = unique(ret.begin(), ret.end()) - ret.begin();
        ret.resize(len);
        return ret;
    }
};