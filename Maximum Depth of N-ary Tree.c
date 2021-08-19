/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int max=INT_MIN;
        for(auto ele: root->children){
            int height=maxDepth(ele);
            if(height>max) max=height;
        }
        return max==INT_MIN?1:max+1;
    }
};
