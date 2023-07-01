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
int find(TreeNode* root ,int &ans)
        {
            if(!root)return 0;
            int left = find(root->left,ans);
            int right = find(root->right,ans);
            ans =  max (ans , left + right + 1);
            return ( 1 + max(left,right));

        }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        find(root,ans);
        return ans -1;
    }
};