class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
            return digits;
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            if(i == digits.size() - 1)
                digits[i]++;
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            digits[i] = tmp % 10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};