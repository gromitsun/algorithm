/*
 * Runtime: 12 ms, faster than 88.63% of C++ online submissions for Single Number II.
 * Memory Usage: 9.9 MB, less than 20.13% of C++ online submissions for Single Number II.
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
        
        for (int i=0; i<32; i++)
        {
            int count = 0;
            for (int x : nums)
            {
                count += (x >> i) & 1;
            }
            res |= (count % 3) << i;
        }
        
        return res;
    }
};

