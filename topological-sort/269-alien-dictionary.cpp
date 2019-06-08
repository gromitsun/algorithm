/* LintCode runtime: 150ms. Beats 58.60%. */
class Solution {
    // adjacency list
    vector<int> adj = vector<int>(26, 0);
    
    // indicator of which letters are included in the dictionary
    vector<bool> valid = vector<bool>(26, false);
    
    // node is being visited?
    vector<bool> visited = vector<bool>(26, false);
    // node has been visited?
    vector<bool> finished = vector<bool>(26, false);
    
    // result reverse-stack
    deque<char> res;
    
    // construct adj list from input
    inline void getAdj(vector<string> &words)
    {
        for (int i=1; i<words.size(); i++)
        {
            for (int j=0; j<min(words[i-1].size(), words[i].size()); j++)
            {
                // find first different letter
                if (words[i-1][j] != words[i][j])
                {
                    adj[words[i-1][j]-'a'] |= 1 << (words[i][j]-'a');
                    break;
                }
            }
        }
    }
    
    // get all letters in dictionary
    inline void getLetters(vector<string> &words)
    {
        for (string& s : words)
        {
            for (char c : s)
            {
                valid[c - 'a'] = true;
            }
        }
    }
    
    // print adj list for debug
    inline void printAdj()
    {
        for (char i=0; i<26; i++)
        {
            if (valid[i])
            {
                cout << (char)(i + 'a') << ": ";
                for (char j=0; j<26; j++)
                {
                    if (adj[i] & (1 << j))
                    {
                        cout << (char)(j + 'a') << ' ';
                    }
                }
                cout << endl;
            }
        }
    }
    
    // dfs to find topological order -- return false if cycles exist
    bool dfs(char i)
    {
        // found a cycle
        if (visited[i])
        {
            return finished[i];
        }
        
        visited[i] = true;
        // continue with next level
        for (char j=0; j<26; j++)
        {
            if ( (adj[i] & (1 << j)) && !dfs(j) )
            {
                return false;
            }
        }
        
        // push node to stack
        res.push_front(i+'a');
        
        finished[i] = true;
        
        // no cycles found
        return true;
    }
    
    
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        
        // at least 2 words are required to get ordering
        if (words.size() < 2)
        {
            return "";
        }
        
        // construct adj list from input
        getAdj(words);
        // get all letters in dictionary
        getLetters(words);
        
        // printAdj();
        
        // iterate over all keys (letters) in adj list
        for (char i=25; i>=0; i--)
        {
            // skip letters not in dictionary
            if (valid[i] && !dfs(i))
            {
                return "";
            }
        }
        
        return string(res.begin(), res.end());
        
    }
};

