/*
788.旋转数字
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

示例:
输入: 10
输出: 4
解释: 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。

作者:syt
日期：2018-01-16
*/

class Solution {
public:
    bool isGood(int n)
    {
        int original = n;
        int tmp = 0;
        int index = 0;
        while(n)
        {
            int val = n%10;
            switch(val)
            {
                case 6:
                    val = 9;
                    break;
                case 9:
                    val = 6;
                    break;
                case 2:
                    val = 5;
                    break;
                case 5:
                    val = 2;
                    break;
                case 0:
                case 1:
                case 8:
                    break;
                default:
                    return false;
            }
            tmp = tmp + val*pow(10, index++);
            n = n/10;
        }
        return (tmp == original)?false:true;
    }
    int rotatedDigits(int N) {
        int ret = 0;
        for(int i = 2; i <= N; ++i)
        {
            if(isGood(i))
                ++ret;
        }
        return ret;
        
    }
};