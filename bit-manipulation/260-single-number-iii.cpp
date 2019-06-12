/*
 * Runtime: 12 ms, faster than 96.42% of C++ online submissions for Single Number III.
 * Memory Usage: 9.7 MB, less than 82.89% of C++ online submissions for Single Number III.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // take XOR of all nums
        int xor_all = 0;
        for (int x : nums)
        {
            xor_all ^= x;
        }
        
        // find a non-zero bit of xor_all -- this is a different bit between the two nums
        int i=0;
        while ( !((xor_all >> i) & 1) )
        {
            i++;
        }
        i = 1 << i;
        
        // use the difference bit to find the two nums
        // by doing two XOR groups
        vector<int> res(2, 0);
        for (int x : nums)
        {
            if (x & i)
            {
                res[0] ^= x;
            }
            else
            {
                res[1] ^= x;
            }
        }
        
        return res;
        
    }
};

