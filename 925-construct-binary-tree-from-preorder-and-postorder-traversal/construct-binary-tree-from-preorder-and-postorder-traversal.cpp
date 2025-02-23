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
    TreeNode* constructTree(int preStart, int postStart, int preEnd, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& mp) {
        if (preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int j = mp[preorder[preStart + 1]];
        int numOfNodesInLeft = j - postStart + 1;

        root->left = constructTree(preStart + 1, postStart, preStart + numOfNodesInLeft, preorder, postorder, mp);
        root->right = constructTree(preStart + numOfNodesInLeft + 1, j + 1, preEnd, preorder, postorder, mp);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < postorder.size(); i++) {
            mp[postorder[i]] = i;
        }
        return constructTree(0, 0, preorder.size() - 1, preorder, postorder, mp);
    }
};