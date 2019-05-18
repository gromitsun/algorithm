class Solution {
    // all solutions
    vector<vector<int>> ret;
    // one solution
    vector<int> sol;
    
    // dfs
    inline void dfs(int k, int n, int start)
    {
        // reached number limit
        if (k == 0)
        {
            // found a solution
            if (n == 0)
            {
                ret.push_back(sol);
            }
            return;
        }
        
        for (int i=start; i<=min(n, 9); i++)
        {
            sol.push_back(i);
            dfs(k-1, n-i, i+1);
            sol.pop_back();
        }
    }
    
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ret;
    }
};

