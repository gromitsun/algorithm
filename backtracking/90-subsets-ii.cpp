class Solution {
    vector<int> unique_nums;
    vector<int> counts;
    
    // all subsets
    vector<vector<int>> ret;
    // one subset
    vector<int> subset;
    
    // get sorted unique nums and counts
    inline void getCounts(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        unique_nums.push_back(prev);
        counts.push_back(0);
        
        for (auto x : nums)
        {
            if (x == prev)
            {
                counts.back()++;
            }
            else
            {
                unique_nums.push_back(x);
                counts.push_back(1);
                prev = x;
            }
        }
    }
    
    // get all subsets
    inline void dfs(int i)
    {
        if (i == unique_nums.size())
        {
            ret.push_back(subset);
            return;
        }
        
        for (int j=0; j<=counts[i]; j++)
        {
            subset.resize(subset.size()+j, unique_nums[i]);
            dfs(i+1);
            subset.resize(subset.size()-j);
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        if (nums.empty())
        {
            return ret;
        }
        
        getCounts(nums);
        
        dfs(0);
        
        return ret;
    }
};

