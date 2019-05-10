/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // global maximum -- max sum under this node
    int m = INT_MIN;
    
    int dfs(TreeNode* node)
    {
        /*
        * return: max sum on path ending at this node
        * update m: max sum under this node
        */
        if (node)
        {
            int l = dfs(node->left);
            int r = dfs(node->right);
            // max sum under this node
            // max sum not going through this node: max(l.first, r.first)
            // max sum going through this node: l.second + r.second + node->val
            m = max(m, l + r + node->val);
            
            return max(max(l + node->val, r + node->val), 0);
        }
        
        return 0;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return m;
    }
};

