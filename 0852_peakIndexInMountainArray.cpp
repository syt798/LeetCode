/*
852.山脉数组的峰顶索引

我们把符合下列属性的数组 A 称作山脉：
A.length >= 3
存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。

示例 1：
输入：[0,1,0]
输出：1

示例 2：
输入：[0,2,1,0]
输出：1
 

提示：
3 <= A.length <= 10000
0 <= A[i] <= 10^6
A 是如上定义的山脉

作者：syt
日期：2018-11-21

思路：求最大值，遍历或者二分查找
*/

//遍历
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int index = 0;
        int max = A[0];
        for(int i = 1; i < A.size(); ++i)
        {
            if(A[i] > max)
            {
                max = A[i];
                index = i;
            }
        }
        return index;
    }
};

//二分查找
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0, end = A.size()-1;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            if(A[mid] > A[mid-1])
                start = mid+1;
            if(A[mid] > A[mid+1])
                end = mid-1;
        }
    }
};