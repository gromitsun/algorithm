class Solution1 {
    // maximum number of transactions allowed
    static constexpr const int& k = 2;
    
    // profit after a maximum of 1 to k transactions
    vector<int> profits = vector<int>(k, 0);
    // reference prices
    vector<int> refs = vector<int>(k, INT_MAX);
    
public:
    int maxProfit(vector<int>& prices) {
        
        for (int x : prices)
        {
            // lowest price preceding current
            refs[0] = min(x, refs[0]);
            // max profit with max 1 transaction
            profits[0] = max(x - refs[0], profits[0]);
            // adjusted lowest price for the second transaction
            refs[1] = min(x - profits[0], refs[1]);
            // profits after max 2 transactions
            profits[1] = max(x - refs[1], profits[1]);
        }
        return profits[k-1];
    }
};


class Solution2 {
    // maximum number of transactions allowed
    static constexpr const int& k = 2;
    
    // minimum cost after the i-th buy
    vector<int> buy = vector<int>(k, INT_MAX);
    // maximum profit after the i-th sell
    vector<int> sell = vector<int>(k, 0);
    
public:
    int maxProfit(vector<int>& prices) {
        
        for (int x : prices)
        {
            // first buy -- lowest price preceding current
            if (x < buy[0])
            {
                buy[0] = x;
            }
            // first sell -- sell price that maximizes profit with max 1 transaction
            else if (x - buy[0] > sell[0])
            {
                sell[0] = x - buy[0];
            }
            
            // second buy
            if (x - sell[0] < buy[1])
            {
                buy[1] = x - sell[0];
            }
            // second sell
            else if (x - buy[1] > sell[1])
            {
                sell[1] = x - buy[1];
            }
        }
        return sell[1];
    }
};


typedef Solution2 Solution;

