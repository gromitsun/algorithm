class Solution {
    // dp array for memoization
    vector<int> dp;
    
    int coinChangeAux(vector<int>& coins, int amount) {
        
        // nothing left
        if (amount == 0)
        {
            return 0;
        }
        
        // not possible to make a change
        if (amount < 0)
        {
            return -1;
        }
        
        // already computed
        if (dp[amount - 1] != INT_MAX)
        {
            return dp[amount - 1];
        }
        
        // recursively compute change
        for (int c : coins)
        {
            int count = coinChangeAux(coins, amount - c);
            if (count != -1)
            {
                dp[amount - 1] = min(count + 1, dp[amount - 1]);
            }
        }
        
        // check if we have found a solution
        if (dp[amount - 1] == INT_MAX)
        {
            dp[amount - 1] = -1;
        }
        
        return dp[amount - 1];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // initialize dp array
        dp = vector<int>(amount, INT_MAX);
        
        return coinChangeAux(coins, amount);
    }
};

