class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[26], N = s.size(), ret = 0;
        for (int i = 0; i < 26; i++)    last[i] = -1;
        int start = 0;
        for (int i = 0; i < N; i++) {
            if (last[s[i] - 'a'] != -1) {
                while (start <= last[s[i] - 'a']) last[s[start++] - 'a'] = -1;
            }
            ret = max(ret, i - start + 1);
            last[s[i] - 'a'] = i;
        }
        return ret;
    }
};