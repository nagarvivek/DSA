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
    vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
   queue<TreeNode*>q;
   q.push(root);
   if (root == NULL) {
       return ans;
   }
   while(q.size())
   {
       int size = q.size();
       while(size--)//loop jab tak chalega jab tak ek level ke sarre elemnts apne left and right child ko bhar nhi dete
       {
           if(size==0)ans.push_back(q.front()->val);
           TreeNode* temp = q.front();
           q.pop();
           if(temp->left)q.push(temp->left);
           if(temp->right)q.push(temp->right);
       }
   }
   return ans;
    }
};