/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root->right && (root->right->val<=root->val || !isValidBST(root->right) || minNode(root->right)->val<=root->val) )  
        return false;
        if(root->left && (root->left->val>=root->val || !isValidBST(root->left) || maxNode(root->left)->val>=root->val))
        return false;
        return true;
    }
    TreeNode* minNode(TreeNode* root)
    {
        while(root->left)
        root=root->left;

        return root;
    }
    TreeNode* maxNode(TreeNode* root)
    {
        while(root->right)
        root=root->right;

        return root;
    }
};
