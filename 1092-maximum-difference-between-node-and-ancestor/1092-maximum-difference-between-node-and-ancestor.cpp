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
class Solution{
    void solve(TreeNode* root,int cmax,int cmin,int &maxd)
    {
     
          if(root==NULL)
          {
              return;
          }
          cmax=max(cmax,root->val);
          cmin=min(cmin,root->val);
          maxd=max(maxd,abs(cmax-cmin));

          solve(root->left,cmax,cmin,maxd);
          
          solve(root->right,cmax,cmin,maxd);

    }
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        int cmax=INT_MIN;   int maxd=0;
        int cmin=INT_MAX;
      
        if(root==NULL)
        {
            return 0 ;
        }
        solve(root,cmax,cmin,maxd);
        return maxd;
    }
};