class Solution {
private:
bool isPalindrome[500][500];
int N;
vector<vector<string> > ret;
string S;
public:
    vector<vector<string> > partition(string s) {
        S = s;
        N = s.size();
        string buf[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                isPalindrome[i][j] = 0;
                if (i == j || (i + 1 == j && s[i] == s[j])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        for (int i = 3; i <= N; i++) {
            for (int st = 0; st + i <= N; st++) {
                int ed = st + i -1;
                if (s[st] == s[ed] && isPalindrome[st + 1][ed - 1]) {
                    isPalindrome[st][ed] = 1;
                }
            }
        }
        partitionHelper(0, 0, 0, "", buf);
        return ret;
    }
    void partitionHelper(int st, int ed, int cnt, string tmp, string buf[]) {
        if (ed >= N) {
            int a;
            a = 1;
            if (st == ed) {
                vector <string> tmp;
                for (int i = 0; i < cnt; i++) {
                    tmp.push_back(buf[i]);
                }
                ret.push_back(tmp);
            }
            return;
        }
        tmp += S[ed];
        if (isPalindrome[st][ed]) {
            buf[cnt] = tmp;
            partitionHelper(ed + 1, ed + 1, cnt + 1, "", buf);
        }
        partitionHelper(st, ed + 1, cnt, tmp, buf);
    }
};