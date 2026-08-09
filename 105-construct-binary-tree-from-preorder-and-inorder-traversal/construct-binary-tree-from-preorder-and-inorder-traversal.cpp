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
    int search(int temp, vector<int> inorder, int left, int right){
        while(left<=right){
            if(temp==inorder[left]){
                return left;
            }
            left++;
            
        }return -1;
    }
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &idx, int left, int right )
    {
        if(left>right){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
       
        int x=search(root->val, inorder, left, right);
        root->left=solve(preorder, inorder, idx, left, x-1);
        root->right=solve(preorder, inorder, idx, x+1, right );

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left=0;
        int right=preorder.size()-1;
        int idx=0;

        return solve(preorder, inorder, idx, left, right );
    }
};