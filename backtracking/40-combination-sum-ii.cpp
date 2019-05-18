class Solution {
    
    vector<int> unique_candidates;
    vector<int> counts;
    
    // solutions
    vector<vector<int>> ret;
    
    // one solution
    vector<int> sol;
    
    // get unique candidates and counts
    void getCounts(vector<int>& candidates)
    {
        // sort candidates
        sort(candidates.begin(), candidates.end());
        
        int i = 0;
        
        for (int x : candidates)
        {
            if (x == i)
            {
                counts.back()++;
            }
            else
            {
                i = x;
                unique_candidates.push_back(x);
                counts.push_back(1);
            }
        }
    }
    
    // DFS
    void dfs(int target, int i)
    {
        // found a solution
        if (target == 0)
        {
            ret.push_back(sol);
            return;
        }
        
        // run out of unique candidates -- not a solution
        if (i >= unique_candidates.size())
        {
            return;
        }
        
        // iterate through unique candidate counts
        for (int n=0; n<=counts[i]; n++)
        {
            if (n*unique_candidates[i] <= target)
            {
                // add n copies of candidate[i]
                sol.resize(sol.size()+n, unique_candidates[i]);
                
                // move to next candidate
                dfs(target-n*unique_candidates[i], i+1);
                
                // remove added candidate[i]
                sol.resize(sol.size()-n);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // get unique candidates and counts
        getCounts(candidates);
        // DFS
        dfs(target, 0);
        
        return ret;
        
    }
};

