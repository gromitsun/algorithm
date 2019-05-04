class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // check special case
        if (n == 1)
        {
            return vector<int>{0};
        }
        
        // construct adjacency list
        vector<unordered_set<int>> adj;
        adj.reserve(n);
        for (int i=0; i<n; i++)
        {
            adj.push_back(unordered_set<int>());
        }
        
        for (const auto& edge : edges)
        {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        // find all leaves
        vector<int> leaves, leaves_next;
        for (int i=0; i<n; i++)
        {
            if (adj[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        
        // breadth first search from leaves
        while(n > 2)
        {
            for (int i : leaves)
            {
                n--;
                for (int j: adj[i])
                {
                    // remove linkage to the leaf
                    adj[j].erase(i);
                    // this is a new leaf
                    if (adj[j].size() == 1)
                    {
                        leaves_next.push_back(j);
                    }
                }
            }
            leaves.clear();
            swap(leaves, leaves_next);
        }
        
        return leaves;
    }
};

