class Solution {
private:
    int N;
public:
    int threeSumClosest(vector<int> &num, int target) {
        int differ = 0x7fffffff, ret;
        N = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < N; i++) {
            int tmpRet = threeSumClosestHelper(num, i, target);
            if (abs(tmpRet - target) < differ) {
                differ = abs(tmpRet - target);
                ret = tmpRet;
            }
        }
        return ret;
    }
    int threeSumClosestHelper(vector<int> &num, int pos, int target) {
        int start = 0, end = N - 1;
        int differ = 0x7fffffff, ret = 0;
        while (start < end) {
            if (pos == start)   start++;
            if (pos == end)     end--;
            if (start >= end)   break;
            int nowv = num[pos] + num[end] + num[start];
            if (abs(nowv - target) < differ) {
                differ = abs(nowv - target);
                ret = nowv;
            }
            if (nowv == target) return target;
            else if (nowv < target) {
                start++;
            } else {
                end--;
            }
        }
        return ret;
    }
};