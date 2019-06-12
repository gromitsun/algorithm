/*
 * Runtime: 12 ms, faster than 97.37% of C++ online submissions for Single Number.
 * Memory Usage: 9.8 MB, less than 30.77% of C++ online submissions for Single Number.
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for (int x : nums)
        {
            res ^= x;
        }
        
        return res;
    }
};

