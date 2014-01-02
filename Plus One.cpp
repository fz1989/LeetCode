class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int N = digits.size();
        int adder = 1;
        for (int i = N - 1; i >= 0 && adder; i--) {
            adder = (digits[i] + adder) / 10;
            digits[i] = (digits[i] + 1) % 10;
        }
        if (adder)  digits.insert(digits.begin(), 1);
        return digits;
    }
};