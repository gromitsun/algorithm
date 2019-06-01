class Solution1 {
    int maxProfitNoLimit(vector<int>& prices)
    {
        int profit = 0;
        for (int i=1; i<prices.size(); i++)
        {
            profit += max(prices[i] - prices[i-1], 0);
        }
        return profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        // edge cases
        if (prices.size() < 2 || k == 0)
        {
            return 0;
        }
        
        // max number of transactions cannot exceed length of prices / 2
        // otherwise, the limit has no effect
        if (k >= prices.size() / 2)
        {
            return maxProfitNoLimit(prices);
        }
        
        // minimum cost after the i-th buy
        vector<int> buy(k+1, INT_MAX);
        // maximum profit after the i-th sell
        vector<int> sell(k+1, 0);
        
        for (int x : prices)
        {
            for (int i=1; i<=k; i++)
            {
                buy[i] = min(x - sell[i-1], buy[i]);
                sell[i] = max(x - buy[i], sell[i]);
            }
        }
        return sell[k];
    }
};


class Solution2 {
    int maxProfitNoLimit(vector<int>& prices)
    {
        int profit = 0;
        for (int i=1; i<prices.size(); i++)
        {
            int diff = prices[i] - prices[i-1];
            if (diff > 0)
            {
                profit += diff;
            }
        }
        return profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        // edge cases
        if (prices.size() < 2 || k == 0)
        {
            return 0;
        }
        
        // max number of transactions cannot exceed length of prices / 2
        // otherwise, the limit has no effect
        if (k >= prices.size() / 2)
        {
            return maxProfitNoLimit(prices);
        }
        
        // minimum cost after the i-th buy
        vector<int> buy(k+1, INT_MAX);
        // maximum profit after the i-th sell
        vector<int> sell(k+1, 0);
        
        for (int x : prices)
        {
            for (int i=1; i<=k; i++)
            {
                int new_buy = x - sell[i-1];
                if (new_buy < buy[i])
                {
                    buy[i] = new_buy;
                }
                else
                {
                    int new_sell = x - buy[i];
                    if (new_sell > sell[i])
                    {
                        sell[i] = new_sell;
                    }
                }
            }
        }
        return sell[k];
    }
};


typedef Solution1 Solution;

