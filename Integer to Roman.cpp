int score[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string bits[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
class Solution {
public:
    string intToRoman(int num) {
        string ret = ""; 
        for (int i = 0; i< 13; i++) {
            int adder = num / score[i];
            for (int j = 0; j < adder; j++) {
                ret += bits[i];
            }
            num -= adder * score[i]; 
        }
        return ret;
    }
};