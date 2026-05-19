class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root!=nullptr) {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        if(!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            if(node->right==nullptr) {
                return node->val;
            }
            else {
                TreeNode* curr=node->right;
                while(curr!=nullptr) {
                    st.push(curr);
                    curr=curr->left;
                }
                return node->val;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }
};
