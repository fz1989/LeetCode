class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector <string> ret;
        map<string, int> mp;
        int N = strs.size();
        for (int i = 0; i < N; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end()) {
                mp.insert(make_pair(s, i));
            } else {
                if (mp[s] != -1) {
                    ret.push_back(strs[mp[s]]);
                    mp[s] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};