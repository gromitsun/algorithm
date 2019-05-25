class Solution {  
    
public:
    int longestSubstring(string s, int k) {
        
        vector<int> count(26, 0);    
        
        // count number of occurence
        for (char c : s)
        {
            count[c-'a']++;
        }
        
        // get max length
        int m = 0;
        int i = 0;
        for (int j=0; j<s.size(); j++)
        {
            if (count[s[j]-'a'] < k)
            {
                m = max(m, longestSubstring(s.substr(i, j-i), k));
                i = j+1;
            }
        }
        if (i == 0)
        {
            return s.size();
        }
        // last substring
        m = max(m, longestSubstring(s.substr(i, s.size()-i), k));
        
        return m;
    }
};

