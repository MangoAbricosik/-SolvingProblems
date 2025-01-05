class Solution {
private:
    std::vector<int> arr;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        inorderTraversal(root->left);
        arr.push_back(root->val);
        inorderTraversal(root->right);
        return arr;
    }
};