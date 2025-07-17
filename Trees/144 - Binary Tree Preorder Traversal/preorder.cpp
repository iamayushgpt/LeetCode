class Solution {
private:
    void traversal(TreeNode* node, vector<int>& ans) {
        if (node == nullptr)
            return;
        ans.push_back(node->val);
        traversal(node->left, ans);
        traversal(node->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};