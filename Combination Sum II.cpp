class Solution {
private:
    vector<vector<int> > ret;
    int N;
    vector<int> sum ;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        N = num.size();
        int s = 0;
        int buf[N];
        for (int i = N - 1; i >= 0; i--) {
            s += num[i];
            sum.push_back(s);
        }
        reverse(sum.begin(), sum.end());
        combinationSum2Helper(0, target, 0, num, buf);
        sort(ret.begin(), ret.end());
        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
        return ret;

    }
    void combinationSum2Helper(int pos, int remain, int deep, vector<int> &num, int buf[]) {
        if (remain == 0) {
            vector <int> tmp;
            for (int i = 0; i < pos; i++) {
                tmp.push_back(buf[i]);
            }
            ret.push_back(tmp);
        }
        if (deep == N || remain <= 0)   return;
        if (remain < num[deep]) return;
        if (remain > sum[deep]) return;
        buf[pos] = num[deep];
        combinationSum2Helper(pos + 1, remain - num[deep], deep + 1, num, buf);
        combinationSum2Helper(pos, remain, deep + 1, num, buf);
    }
};