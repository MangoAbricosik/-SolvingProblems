class Solution {
    int depth = 0;
    int minDepthVal = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        depth++;

        if (!root) {
            depth--;
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (depth < minDepthVal)
                minDepthVal = depth;
            depth--;
            return minDepthVal;
        }

        if (root->left)
            minDepth(root->left);
        if (root->right)
            minDepth(root->right);

        depth--;
        return minDepthVal;
    }
};