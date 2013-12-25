#include <algorithm>
using namespace std;
class Solution {
    vector <pair<int, int> >num;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            num.push_back(make_pair(numbers[i], i + 1));
        }
        sort(num.begin(), num.end());
        vector<int> ret;
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = num[l].first + num[r].first;
            if (target == sum) {
                ret.push_back(min(num[l].second, num[r].second));
                ret.push_back(max(num[l].second, num[r].second));
                break;
            }
            else if (sum > target) r--;
            else if (sum < target) l++;
        }
        return ret;
    }
};