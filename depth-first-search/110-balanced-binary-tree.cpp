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
    // function to get tree height recursively using DFS
    int getHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        // we use -1 as a signal for imbalance
        if (left < 0 || right < 0 || abs(left - right) > 1)
        {
            return -1;
        }
        
        return max(left, right) + 1;        
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};

