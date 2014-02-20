class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> m, s;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            m.insert(make_pair(num[i], num[i]));
            s.insert(make_pair(num[i], 1));
        }
        for (int i = 0; i < n; i++) {
            if (m.find(num[i] - 1) != m.end()) {
                unionSet(m, s, m.find(num[i] - 1)->first, num[i]);
            } 
            if (m.find(num[i] + 1) != m.end()) {
                unionSet(m, s, m.find(num[i] + 1)->first, num[i]);
            }
        }
        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret = max(ret, s[num[i]]);
        }
        return ret;
    }
    int findSet(unordered_map<int, int> &m, int u) {
        if (m[u] != u) {
            m[u] = findSet(m, m[u]);
        }
        return m[u];
    }
    void unionSet(unordered_map<int, int>& m, unordered_map<int, int> &s, int u, int v) {
        int rootu = findSet(m, u), rootv = findSet(m, v);
        if (rootu == rootv) return;
        if (s[rootu] < s[rootv]) {
            s[rootv] += s[rootu];
            m[rootu] = m[rootv];
        } else {
            s[rootu] += s[rootv];
            m[rootv] = m[rootu];
        }
    }
};