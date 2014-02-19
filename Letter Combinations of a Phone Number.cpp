string codeBoard[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
private:
   vector<string> ret; 
   string str;
   
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        str = digits;
        letterCombinationsHelper("", len, 0);
        return ret;
    }
    void letterCombinationsHelper(string buf, int N, int deep) {
        if (deep == N) {
            ret.push_back(buf);
            return;
        }
        int n = codeBoard[str[deep] - '0'].size();
        for (int i = 0; i < n; i++) {
            letterCombinationsHelper(buf + codeBoard[str[deep] - '0'][i], N, deep + 1);
        }
    }
};