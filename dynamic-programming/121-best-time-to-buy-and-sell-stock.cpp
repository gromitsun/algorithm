class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // min price so far
        int min_price = INT_MAX;
        // max profit so far
        int max_profit = 0;
        for (int x : prices)
        {
            if (x < min_price)
            {
                min_price = x;
            }
            else 
            {
                max_profit = max(x-min_price, max_profit);
            }
        }
        return max_profit;
    }
};

