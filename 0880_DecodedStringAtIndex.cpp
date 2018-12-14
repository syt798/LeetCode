/*
880.索引处的解码字符串
给定一个编码字符串 S。为了找出解码字符串并将其写入磁带，从编码字符串中每次读取一个字符，并采取以下步骤：
如果所读的字符是字母，则将该字母写在磁带上。
如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

示例 1：
输入：S = "leet2code3", K = 10
输出："o"
解释：
解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
字符串中的第 10 个字母是 "o"。

示例 2：
输入：S = "ha22", K = 5
输出："h"
解释：
解码后的字符串为 "hahahaha"。第 5 个字母是 "h"。

示例 3：
输入：S = "a2345678999999999999999", K = 1
输出："a"
解释：
解码后的字符串为 "a" 重复 8301530446056247680 次。第 1 个字母是 "a"。

作者:syt
日期：2018-12-14
*/


//"y959q969u3hb22odq595" 222280369 数据内存溢出
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string curString = "";
        for(int i = 0; i < S.length(); ++i)
        {
            if(curString.length() > K)
                break;
            if(S[i] >= 'a' && S[i] <= 'z')
            {
                curString += S.substr(i, 1);
            }
            
            if(S[i] >= '0' && S[i] <= '9')
            {
                int number = S[i] - '0';
                string tmp = curString;
                for(int j = 1; j < number; ++j)
                    curString += tmp;
            }
            
        }
        if(curString.length() < K)
            return "";
        return curString.substr(K-1, 1);
        
    }
};


//官方解
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long size = 0;
        int length = S.size();
        for(int i = 0; i < length; ++i)
        {
            if(isdigit(S[i]))
                size *= (S[i] - '0');
            else
                ++size;
        }
        
        for(int i = length-1; i >= 0; --i)
        {
            K %= size;
            if(K == 0 && isalpha(S[i]))
                return (string)""+S[i];
            if(isdigit(S[i]))
                size /= (S[i] - '0');
            else
                --size;
        }
    }
};