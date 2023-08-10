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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int>inorder, v;
    v=preorder;
    sort(v.begin(), v.end());
    inorder=v;
    if(preorder.size()==0){return NULL;}
    map<int, int>m;
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]]=i;
    }
    TreeNode* root=formtree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    return root;
}
TreeNode* formtree(vector<int>& preorder, int pst, int pen, vector<int>& inorder, int inst, int inen, map<int, int>& m){
    if(pst>pen || inst>inen){return NULL;}
    TreeNode* root=new TreeNode(preorder[pst]);
    int pos=m[preorder[pst]];
    int lft=pos-inst;
    root->left=formtree(preorder, pst+1, pst+lft, inorder, inst, pos-1, m);
    root->right=formtree(preorder, pst+lft+1, pen, inorder, pos+1, inen, m);
    return root;
}
};