class Solution {
    int level = 2;
public:
    void dfs(TreeNode* first, TreeNode* second) {
        if (!first || !second)
            return;


        if (level % 2 == 0) {
            int temp = move(first->val);
            first->val = move(second->val);
            second->val = temp;
        }

        level++;
        dfs(first->left, second->right);
        level--;
        dfs(first->right, second->left);
        level--;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right);
        return root;
    }
};