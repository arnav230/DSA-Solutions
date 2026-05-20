class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;
            for(int i=0; i<size;i++) {
                TreeNode* node=q.front();
                q.pop();
                if(node->left !=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                if(i==size-1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};
