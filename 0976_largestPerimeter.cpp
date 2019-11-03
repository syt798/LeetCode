/*
976. 三角形的最大周长
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
如果不能形成任何面积不为零的三角形，返回 0。

示例 1：
输入：[2,1,2]
输出：5

示例 2：
输入：[1,2,1]
输出：0

示例 3：
输入：[3,2,3,4]
输出：10

示例 4：
输入：[3,6,2,3]
输出：8

作者:syt
日期：2018-01-13
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int ret = 0;
        if(A.size() < 3)
            return ret;
        sort(A.begin(), A.end());
        int x,y,z;
        bool isFind = false;
        for(int i = A.size()-1; i >= 2; --i)
        {
            for(int j = i-1; j >= 1; --j)
            {
                for(int k = j-1; k >= 0; --k)
                {
                    x = A[i];
                    y = A[j];
                    z = A[k];
                    if((x+y > z)&&(x+z > y)&&(y+z > x))
                    {
                        isFind = true;
                        ret = x+y+z;
                        break;
                    }
                    else
                        break;
                }
                if(isFind)
                    break;
            }
            if(isFind)
                break;
                
        }
        return ret;
    }
};