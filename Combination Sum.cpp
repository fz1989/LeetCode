class Solution {
private:
    vector<vector<int> > ret;
    int N;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        N = candidates.size();
        int buf[N];
        for (int i = 0; i < N; i++) buf[i] = 0;
        combinationSumHelper(0, target, candidates, buf);
        sort(ret.begin(), ret.end());
        return ret;
    }

    void combinationSumHelper(int pos, int remain, vector<int> &candidates, int buf[]) {
        if (remain == 0) {
            vector <int> tmp;
            for (int i = 0; i < pos; i++) {
                for (int j = 0; j < buf[i]; j++) {
                    tmp.push_back(candidates[i]);
                }
            }
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            return;
        }
        if (pos == N)   return;
        for (int i = 0; i <= remain / candidates[pos]; i++) {
            buf[pos] = i;
            combinationSumHelper(pos + 1, remain - i * candidates[pos], candidates, buf);
        }
        buf[pos] = 0;
    }
};