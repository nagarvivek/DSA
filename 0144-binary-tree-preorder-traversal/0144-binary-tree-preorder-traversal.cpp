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
// PRE-ORDER Traversal - N L R
// Store root/node then traverse the left subtree till NULL and then traverse the right subtree
    void preOrder(TreeNode* node, vector<int>& result) {
        if (node == NULL)
        {
            return ; 
        }

        result.push_back(node -> val) ;
        preOrder(node -> left, result) ;
        preOrder(node -> right, result) ;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result ;
        preOrder(root, result) ;
        return result ;
    }
};