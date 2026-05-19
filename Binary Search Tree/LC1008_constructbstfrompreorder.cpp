class Solution {
public:
    TreeNode* insertinBST(TreeNode* root, int val) {
    if(root==nullptr) {
        root=new TreeNode(val);
        return root;
    }
    else {
        if(root->val<val) {
            root->right=insertinBST(root->right, val);
        }
        else root->left=insertinBST(root->left, val);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= new TreeNode(preorder[0]);
        int size=preorder.size();
        for(int i=1;i<size;i++) {
            root=insertinBST(root, preorder[i]);
        }
        return root;
    }
};
