class Solution {
public:
    void solver(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left){
            solver(root->left,ans);            
        }
        if(root->right){
            solver(root->right,ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solver(root,ans);
        return ans;
    }
};