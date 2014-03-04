class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int sum = 0, total = 0, start = -1;
        for (int i = 0; i < N; i++) {
            sum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if (sum < 0) {
                sum = 0;
                start = i;
            }
        }
        if (total < 0)  return -1;
        return          start + 1;
    }
};