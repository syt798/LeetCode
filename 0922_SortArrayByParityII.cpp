/*
922.按奇偶排序数组II
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
你可以返回任何满足上述条件的数组作为答案。

示例：
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

作者:syt
日期：2018-11-20
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1;
        int even = 0;
        for(; even < A.size() - 1; even = even + 2)
        {
            if((A[even] & 1) != 0)
            {
                while((A[odd] & 1) != 0)
                {
                    odd = odd + 2;
                }
                int tmp = A[odd];
                A[odd] = A[even];
                A[even] = tmp;
            }
        }
        return A;
    }
};