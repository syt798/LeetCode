class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int pre = 1;
        int cur = 2;
        while(n > 2)
        {
            int tmp = pre;
            pre = cur;
            cur = tmp + cur;
            n--;
        }
        return cur;
            
    }
};