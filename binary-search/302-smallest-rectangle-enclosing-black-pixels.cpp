/* LintCode 600:
 * https://www.lintcode.com/problem/smallest-rectangle-enclosing-black-pixels 
 * */

ass Solution {
    inline static bool checkRow(const vector<char> &v)
    {
        for (auto c : v)
        {
            if (c == '1')
                return true;
        }
        return false;
    }
    
    inline static bool checkColumn(const vector<vector<char>> &image, int col)
    {
        for (const auto& row : image)
        {
            if (row[col] == '1')
                return true;
        }
        return false;
    }
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // check empty input
        if (image.empty())
            return 0;
        if (image[0].empty())
            return 0;
            
        // binary search for edge in -x direction
        int l = 0, r = x;
        
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (checkRow(image[m]))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        
        int x1 = l;
        
        // binary search for edge in +x direction
        l = x + 1, r = image.size();
        
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (checkRow(image[m]))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        int x2 = l;
        
        
        // binary search for edge in -y direction
        l = 0, r = y;
        
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (checkColumn(image, m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        
        int y1 = l;
        
        // binary search for edge in +y direction
        l = y + 1, r = image[0].size();
        
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (checkColumn(image, m))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        int y2 = l;
        
        // calculate area
        return (x2 - x1) * (y2 - y1);
    }
};

