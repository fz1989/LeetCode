class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size(), min_len = 0x7fffffff;
        vector<int> lens;
        string ret = "";
        if (len == 0)   return "";
        for (int i = 0; i < len; i++) {
            lens.push_back(strs[i].size());
            min_len = min(lens[i], min_len);
        }
        for (int i = 0; i < min_len; i++) {
            bool flag = true;
            for (int j = 1; j < len; j++) {
                if (strs[j][i] != strs[j - 1][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)   ret += strs[0][i];
            else        break;
        }
        return ret;
    }
};