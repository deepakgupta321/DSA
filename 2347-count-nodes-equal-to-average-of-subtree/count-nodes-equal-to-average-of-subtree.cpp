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
    pair<int,int> solve(TreeNode* root, int &ans){
        if(root==NULL){
            return{0,0};
        }
        auto p1=solve(root->left,  ans);
        auto p2=solve(root->right, ans);
        int sum=root->val+p1.first+p2.first;
        int n=1+p1.second+p2.second;
        if(sum/n==root->val){
            ans=ans+1;
        }
        return {sum,n};


    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        pair<int,int> x;
        x=solve(root, ans);
        return ans;
    }
};