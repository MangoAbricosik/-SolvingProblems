class Solution {
private:
    std::vector<int> arr;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        arr.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return arr;
    }
};