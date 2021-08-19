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
class FindElements {
private: 
    unordered_set<int> s; 
    void recover(TreeNode* root){
        if(!root) return;
        if(root->val==-1) {
            root->val=0;
            s.insert(root->val);
        }
        else s.insert(root->val);
        if(root->left) root->left->val=2*root->val + 1;
        if(root->right) root->right->val=2*root->val + 2;
        recover(root->left);
        recover(root->right);
    }
public:
    FindElements(TreeNode* root) {
        recover(root);
    }
    
    bool find(int target) {
        return s.find(target)!=s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
