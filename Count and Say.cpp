class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 1; i < n; i++) {
            ret = countAndSayHelper(ret);
        }
        return ret;
    }
    string countAndSayHelper(string str) {
        int n = str.size(), cnt = 0;
        char pre = str[0];
        stringstream ss;
        for (int i = 0; i <= n; i++) {
            if (i < n && str[i] == pre) {
                cnt++;
            } else {
                ss << cnt << pre;
                cnt = 1;
                if (i < n)  pre = str[i];
            }
        }
        return ss.str();
    }
};