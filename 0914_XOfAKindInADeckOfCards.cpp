/*
914.卡牌分组
给定一副牌，每张牌上都写着一个整数。
此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。
 
示例 1：
输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]

示例 2：
输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。

示例 3：
输入：[1]
输出：false
解释：没有满足要求的分组。

示例 4：
输入：[1,1]
输出：true
解释：可行的分组是 [1,1]

示例 5：
输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：
1 <= deck.length <= 10000
0 <= deck[i] < 10000

作者:syt
日期：2019-04-08
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> counts;
        int count = 1;
        for(int i = 0; i < deck.size()-1; ++i)
        {
            if(deck[i] == deck[i+1])
                ++count;
            else
            {
                counts.push_back(count);
                count = 1;
            }
        }
        counts.push_back(count);
        sort(counts.begin(), counts.end());
        if(counts.empty())
            return false;
        int X = counts[0];
        for(int i = 1; i < counts.size(); ++i)
        {
            for(int j = 2; j < X; ++j)
            {
                if(X % j == 0 && counts[i] % j == 0)
                {
                    X = j;
                    break;
                }
            }
            if(counts[i] % X != 0)
            {                  
                 return false;
            }
        }
        
        if(X < 2)
            return false;
        return true;
    }
};