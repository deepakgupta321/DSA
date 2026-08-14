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
    void solve(TreeNode* root, pair<long long, long long> x, bool &ans){
        if(root==NULL) return;

        if(root->val<=x.first || root->val>=x.second){
            ans=false;
        }

        solve(root->left, {x.first, root->val}, ans);
        solve(root->right, {root->val, x.second}, ans);
    }

    void solve1(TreeNode* root, long long &prev, bool &ans1){
        if(root==NULL) return;

        solve1(root->left, prev, ans1);
        if(root->val<=prev) ans1=false;
        prev=root->val;
        solve1(root->right, prev, ans1);
    }
    bool isValidBST(TreeNode* root) {




        // bool ans=true;
        // if(root->left==NULL and root->right==NULL) return ans;
        // solve(root, {LLONG_MIN, LLONG_MAX}, ans);
        // return ans;

        bool ans1=true;
        long long prev=LLONG_MIN;
        solve1(root, prev, ans1);
        return ans1;
        
    }
};