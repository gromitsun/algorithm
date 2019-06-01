class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // min cost after last buy
        int buy = INT_MAX;
        // max profit after last sell
        int sell = 0;
        for (int x : prices)
        {
            buy = min(x - sell, buy);
            sell = max(x - buy - fee, sell);
        }
        return sell;
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // min cost after last buy
        int buy = INT_MAX;
        // max profit after last sell
        int sell = 0;
        for (int x : prices)
        {
            if (x - sell < buy)
            {
                buy = x - sell;
            }
            else if (x - buy - fee > sell)
            {
                sell = x - buy - fee;
            }
        }
        return sell;
    }
};


typedef Solution2 Solution;

