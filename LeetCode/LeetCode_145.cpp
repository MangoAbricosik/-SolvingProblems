class Solution {
private:
    std::vector<int> arr;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        arr.push_back(root->val);
        return arr;
    }
};