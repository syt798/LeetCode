class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack == needle)
            return 0;
        int hn = haystack.length();
        int nn = needle.length();
        for(int i = 0; i < hn-nn+1; ++i)
        {
            string tmp = haystack.substr(i, nn);
            if(tmp == needle)
                return i;
        }
        return -1;
    }
};