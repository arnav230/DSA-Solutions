class Solution {
public:
    int count=0;
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        countNodes(root->left);
        count++;
        countNodes(root->right);
        return count;
    }
};
