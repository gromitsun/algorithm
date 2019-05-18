class Solution {
    
    // all solutions
    vector<vector<int>> ret;
    
    // one solution
    vector<int> sol;
    
    // DFS
    void dfs(vector<int>& candidates, int target, int start)
    {
        // found a solution
        if (target == 0)
        {
            ret.push_back(sol);
            return;
        }
        
        // iterate over candidates
        for (int i=start; i<candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                sol.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i);
                sol.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ret;
    }
};

