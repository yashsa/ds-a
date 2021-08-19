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
private:
    int findMax(TreeNode* root){
        if(!root) return -99999;
        return max(root->val,findMax(root->right));
    }
    int findMin(TreeNode* root){
        if(!root) return 99999;
        return min(root->val,findMin(root->left));
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        int leftMax = findMax(root->left);
        int rightMin = findMin(root->right);
        return min(
            min(abs(leftMax - root->val),abs(rightMin - root->val)),
            min(getMinimumDifference(root->left),getMinimumDifference(root->right))
        );
    }
};Minimum Absolute Difference in BST
