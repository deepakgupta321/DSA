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
    bool check(TreeNode* x1, TreeNode* x2){
        if(x1==NULL and x2==NULL){
            return true;
        }
        if(x1==NULL or x2==NULL){
            return false;
        }
        if(x1->val!=x2->val){
            return false;
        }
        
        bool x=check(x1->left, x2->right);
        bool y=check(x1->right, x2->left);

        if(x==true && y==true){
            return true;
        }
        else {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {

        TreeNode* x1=root->left;
        TreeNode* x2=root->right;

        
        return check(x1, x2);
    }
};