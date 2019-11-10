class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        bool result = true;
        int start = 0;
        int end = str.length() - 1;
        while(start < end)
        {
            if(str[start] != str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return result;
    }
};