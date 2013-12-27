class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        for (int i = 0; i < numRows; i++) {
            vector <int> arr;
            arr.push_back(1);
            for (int j = 1; j < i; j++) {
                if (j < i);
                    arr.push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
            }
            if (i) arr.push_back(1);
            ret.push_back(arr);
        }
        return ret;
    }
};