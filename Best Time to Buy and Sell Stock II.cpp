class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        int n = prices.size();
        if (n == 0) return 0;
        int current_max = prices[0], current_min = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] >= current_max) {
                current_max = prices[i];   
            } else {
                ret += (current_max - current_min);
                current_max = prices[i];
                current_min = prices[i];
            }
        }
        if (current_max - current_min > 0)
            ret += (current_max - current_min);
        return ret;
    }
};