class Solution {
public:
    TreeNode* findlr(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlr(root->left);
        lastright->right=rightchild;
        return root->left;
    }    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key) return helper(root);
        TreeNode* dummy=root;
        while(root){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else root=root->left;
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                }
                else root=root->right;
            }
        }
        return dummy;
    }
};