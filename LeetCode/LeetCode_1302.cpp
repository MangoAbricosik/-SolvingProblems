class Solution {
    map<int, int> dict;
    int level = 0;
public:
    void dfs(TreeNode* root) {
        if (!root)
            return;

        level++;
        dict[level] += root->val;
        dfs(root->left);
        dfs(root->right);
        level--;
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root);
        int res = -1;
        for (auto& item : dict)
            res = item.second;
        return res;
    }
};