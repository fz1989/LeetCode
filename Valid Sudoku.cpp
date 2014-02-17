class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> flagR(9, 0);
        vector<int> flagC(9, 0);
        vector<int> flagN(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int pos = board[i][j] - '0';
                int k = i / 3 * 3 + j / 3;
                if (flagR[i] & (1 << pos))  return false;
                if (flagC[j] & (1 << pos))  return false;
                if (flagN[k] & (1 << pos))  return false;
                flagR[i] |= (1 << pos);
                flagC[j] |= (1 << pos);
                flagN[k] |= (1 << pos);
            }
        }
        return true;
    }
};