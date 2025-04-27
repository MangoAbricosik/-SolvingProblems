class Solution {
public:
    void dfs(TreeNode* root) {
        if (!root)
            return;

        TreeNode* temp = move(root->left);
        root->left = move(root->right);
        root->right = move(temp);

        dfs(root->left);
        dfs(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};