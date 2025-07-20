class Solution {
private:
    void traversal(TreeNode* node, vector<int>& ans) {
        if (node == nullptr)
            return;
        traversal(node->left, ans);
        traversal(node->right, ans);
        ans.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};