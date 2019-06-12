/*
 * Runtime: 52 ms, faster than 96.61% of C++ online submissions for Counting Bits.
 * Memory Usage: 9.5 MB, less than 80.84% of C++ online submissions for Counting Bits.
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        
        for (int i=1; i<=num; i++)
        {
            res[i] = res[i >> 1] + (i & 1);
        }
        
        return res;
    }
};

