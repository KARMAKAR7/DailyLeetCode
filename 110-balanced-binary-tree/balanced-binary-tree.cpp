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
    pair<int,bool>solve(TreeNode * root){
        if(!root){
            return{0, true};
        }
        auto left = solve(root->left);
        auto right = solve(root->right);

        bool blan = left.second && right.second && (abs(left.first - right.first )<= 1);


        int h = 1 + max(left.first , right.first);
        return {h,blan};
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};