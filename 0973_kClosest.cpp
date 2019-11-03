/*
973.最接近原点的K个点
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
（这里，平面上两点之间的距离是欧几里德距离。）
你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

示例 1：
输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。

示例 2：
输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）

作者:syt
日期：2018-01-13
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        if(points.size() < K)
            return ret;
        vector<int> indexs;
        vector<double> diss;
        for(int i = 0; i < points.size(); ++i)
        {
            double dis = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            indexs.push_back(i);
            diss.push_back(dis);
        }
        
        for(int i = 0; i < diss.size()-1; ++i)
        {
            for(int j = 0; j < diss.size()-i-1; ++j)
            {
                if(diss[j] > diss[j+1])
                {
                    double tmp_dis = diss[j];
                    diss[j] = diss[j+1];
                    diss[j+1] = tmp_dis;
                    
                    int tmp_index = indexs[j];
                    indexs[j] = indexs[j+1];
                    indexs[j+1] = tmp_index;
                }
            }
        }
        for(int i = 0; i < K; ++i)
        {
            ret.push_back(points[indexs[i]]);
        }
    
        return ret;
    }
};