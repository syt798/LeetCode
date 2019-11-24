class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int profit = 0;
        int cost = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] - cost > profit)
            {
                profit = prices[i] - cost;
            }
            
            if(prices[i] < cost)
                cost = prices[i];
        }
        
        return profit;
    }
};