class Solution {
private:
    inline int char2int(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(string s) {
        int ret = 0, sum = 0, pre;
        int N = s.length();
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                pre = sum = char2int(s[0]);
                continue;
            }
            int now = char2int(s[i]);
            if (now == pre) {
                sum += now; 
            } else if (now < pre) {
                ret += sum;
                sum = now;
            } else {
                sum = now - pre;
            }
            pre = now;
        }
        return ret + sum;
    }
};