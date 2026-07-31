/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==NULL){
            return 0;
        }
        
        int left=lca(root->left, p,q, ans);
        int right=lca(root->right, p, q,ans);
        int total=0;
        
        int self=0;
        if(root==p or root==q){
            self=1;
        }
        total=left+right+self;
        if(ans==NULL and total==2){
            ans=root;
        }

        return total;
        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        lca(root, p, q, ans);
        return ans;


    }
};