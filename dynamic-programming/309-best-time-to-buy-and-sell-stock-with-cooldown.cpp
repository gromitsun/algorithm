class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // min cost after last buy so far
        int buy = INT_MAX;
        // max profit after last sell so far
        int sell = 0;
        // max profit after last sell that is at least 1 timestep before this timestep
        int cool = 0;
        
        for (int x : prices)
        {
            buy = min(x - cool, buy);
            cool = sell;
            sell = max(x - buy, sell);
        }
        
        return sell;
    }
};

