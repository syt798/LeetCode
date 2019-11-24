class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        if(s.empty())
            return result;
        
        int end = s.length()-1;
        while(s[end] == ' ' && end >= 0)
        {
            --end;
        }
        
        for(int i = end; i >= 0; --i)
        {
            if(s[i] == ' ')
                break;
            else
                ++result;   
        }
        return result;
    }
};