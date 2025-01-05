class Solution {
    int depthTree = 0;
    int maxDepthTree = 0;
public:
    int maxDepth(TreeNode* root) {
        depthTree++;

        if (!root) {
            depthTree--;
            return maxDepthTree;
        }

        if (depthTree > maxDepthTree)
            maxDepthTree = depthTree;

        if (root->left == nullptr && root->right == nullptr) {
            depthTree--;
            return maxDepthTree;
        }

        if (root->left)
            maxDepth(root->left);
        if (root->right)
            maxDepth(root->right);
        depthTree--;
        return maxDepthTree;

    }
};