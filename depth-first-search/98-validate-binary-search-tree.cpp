/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive dfs
class Solution {
    
    // previous value in in-order traversal
    int prev = INT_MIN;
    // is this the first node?
    bool isfirst = true;
    
    // inorder traversal
    bool inorder(TreeNode* node)
    {
        if (node)
        {
            // check left, node, right respectively,
            // and return immediately upon false
            if (!inorder(node->left))
            {
                return false;
            }

            if (isfirst)
            {
                isfirst = false;
            }
            else if (node->val <= prev)
            {
                return false;
            }
            
            // update previous value
            prev = node->val;

            if (!inorder(node->right))
            {
                return false;
            }
        }
        
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};

