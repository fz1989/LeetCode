class Solution {
public:
    string addBinary(string a, string b) {
        string ret="";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.size(), len_b = b.size();
        int adder = 0;
        for (int i = 0; i < max(len_a, len_b); i++) {
            int num_a = i < len_a ? a[i] - '0' : 0;
            int num_b = i < len_b ? b[i] - '0' : 0;
            int num = (num_a + num_b + adder) % 2;
            adder = (num_a + num_b + adder) / 2;
            if (num)    ret += "1";
            else        ret += "0";
            
        }
        if (adder) ret += "1";
        reverse(ret.begin(), ret.end());
        return ret;
        
    }
};