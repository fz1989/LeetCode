class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)     return s;
        int zig = 2 * nRows - 2;
        int N = s.size();
        string ret = "";
        for (int i = 0; i < nRows; i++) {
            int step = zig - 2 * i;
            if (step == 0)  step = zig;
            for (int j = i; j < N; ) {
                ret += s[j];
                j += step;
                if (step == 0 || step == zig)   step = zig;
                else {
                    step = zig - step;
                }
            }
        }
        return ret;
    }
};