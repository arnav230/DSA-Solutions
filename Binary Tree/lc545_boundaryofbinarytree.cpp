class Solution {
public:

    vector<int> ans;
    bool leaf(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        return false;
    }
    void leftPart(TreeNode* root) {

        TreeNode* curr = root->left;
        while(curr) {
            if(!leaf(curr)) {
                ans.push_back(curr->val);
            }

            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }

    void addLeafNodes(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        if(leaf(root)) {
            ans.push_back(root->val);
            return;
        }
        addLeafNodes(root->left);
        addLeafNodes(root->right);
    }

    void rightPart(TreeNode* root) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while(curr) {

            if(!leaf(curr)) {
                temp.push_back(curr->val);
            }

            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return ans;
        }
        if(!leaf(root)) {
            ans.push_back(root->val);
        }
        leftPart(root);
        addLeafNodes(root);
        rightPart(root);
        return ans;
    }
};
