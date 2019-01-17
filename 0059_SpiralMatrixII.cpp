/*
59.螺旋矩阵II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

作者:syt
日期：2018-01-17
*/

class Solution {
public:
    void circle(vector<vector<int>>& ret, int n, int start, int& number)
    {
        int endY = n-1-start;
        int endX = n-1-start;
        
        for(int i = start; i <= endY; ++i)
            ret[start][i] = number++;
        
        if(start < endY)
        {
            for(int i = start+1; i <= endY; ++i)
                ret[i][endX] = number++;
        }
        
        if(start < endX && start < endY)
        {
            for(int i = endX-1; i >= start; --i)
                ret[endY][i] = number++;
        }
        if(start < endX && start < endY-1)
        {
            for(int i = endY-1; i >= start+1; --i)
                ret[i][start] = number++;
        }
        
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int start = 0;
        int number = 1;
        while(n > start*2)
        {
            circle(ret, n, start, number);
            ++start;
        }
        return ret;
    }
};