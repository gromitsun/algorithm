/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive DFS
class Solution {
    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    
    // in-order traversal
    void inorder(TreeNode* node)
    {
        if (node)
        {
            inorder(node->left);
            if (prev)
            {
                prev->left = NULL;
                prev->right = node;
            }
            else
            {
                head = node;
            }
            prev = node;
            inorder(node->right);
        }
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        prev->left = NULL;
        prev->right = NULL;
        return head;
    }
};

