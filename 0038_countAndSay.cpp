class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string result = "1";
        for(int i = 1; i < n; ++i)
        {
            string tmp = "";
            int j = 0;
            while(j < result.length())
            {
                int count = calNum(result, j, result[j]);
                tmp += to_string(count) + result.substr(j, 1);
                j += count;
            }
            result = tmp;
        }
        return result;
    }
    int calNum(string str, int start, char target)
    {
        int count = 0;
        for(int i = start; i < str.length(); ++i)
        {
            if(str[i] == target)
                count++;
            else
                break;
        } 
        return count;
    }
};