class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (beginWord.size() <= 1)
            return beginWord.size() + 1;
        
        // find endWord in wordList
        int target = -1;
        for (int i=0; i<wordList.size(); i++)
        {
            if (wordList[i] == endWord)
            {
                target = i;
                break;
            }
        }
        
        // endWord not in wordList
        if (target < 0)
            return 0;
        
        // build hash map
        unordered_map<string, vector<int>> dict;
        
        for (int i=0; i<wordList.size(); i++)
        {
            string& s = wordList[i];
            for (int j=0; j<s.size(); j++)
            {
                string key = s.substr(0, j) + "*" + s.substr(j+1, s.size()-j-1);
                auto iter = dict.find(key);
                if (iter == dict.end())
                {
                    dict.insert({key, vector<int>{i}});
                }
                else
                {
                    (*iter).second.push_back(i);
                }
            }
        }
        
        
        // BFS
        int len = 1;
        int n_current = 1;
        int n_next = 0;
        
        queue<int> q;
        q.push(-1);
        
        // track if we have visited the word
        vector<char> visited(wordList.size(), 0);
        
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            n_current--;
            
            string& word = i < 0 ? beginWord : wordList[i];
            
            // check if we have hit the word
            if (i == target)
            {
                return len;
            }
            
            // iterate through letters in the current word
            for (int j=0; j<word.size(); j++)
            {
                string key = word.substr(0, j) + "*" + word.substr(j+1, word.size()-j-1);
                // find next nodes
                auto iter = dict.find(key);
                if (iter != dict.end())
                {
                    for (int k : (*iter).second)
                    {
                        if (!visited[k])
                        {
                            q.push(k);
                            visited[k] = 1;
                            n_next++;
                        }
                    }
                }
            }
            
            // move to next level
            if (n_current == 0)
            {
                swap(n_current, n_next);
                len++;
            }
            
        }
        
        
        return 0;
        
    }
};

