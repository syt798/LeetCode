class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int start = 0, end = s.length() - 1;
        while(start < end)
        {
            char cstart = tolower(s[start]);
            char cend = tolower(s[end]);
            if(!isalnum(cstart))
            {
                ++start;
            }
            else if(!isalnum(cend))
            {
                --end;
            }
            else
            {
                if(cstart == cend)
                {
                    ++start;
                    --end;
                }
                else
                    return false;
            }
        }
        return true;
    }
};