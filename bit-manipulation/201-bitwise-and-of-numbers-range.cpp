/*
 * Runtime: 8 ms, faster than 97.80% of C++ online submissions for Bitwise AND of Numbers Range.
 * Memory Usage: 8.2 MB, less than 23.68% of C++ online submissions for Bitwise AND of Numbers Range.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m & n;
        n = n - m;
        char i = 0;
        while (n)
        {
            n >>= 1;
            i++;
        }
        return (res >> i) << i;
    }
};

