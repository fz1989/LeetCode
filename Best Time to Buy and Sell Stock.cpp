class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N == 0) return 0;
        int current_min = prices[0], ret = 0;
        for (int i = 1; i < N; i++) {
            if (prices[i] > current_min) {
                ret = max(ret, prices[i] - current_min);
            } else {
                current_min = min(current_min, prices[i]);
            }
        }
        return ret;
    }
};