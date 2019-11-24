class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int max = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            int d = prices[i] - prices[i - 1];
            if(d > 0)
                max += d;
        }
        return max;
    }
};