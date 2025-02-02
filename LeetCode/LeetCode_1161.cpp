class Solution {
    int depthTree = 0;
    map<int, int> maxSum;
public:
    void createDict(TreeNode* root) {
        if (!root) {
            depthTree--;
            return;
        }

        depthTree++;
        createDict(root->left);
        maxSum[depthTree] += root->val;
        depthTree++;
        createDict(root->right);
        depthTree--;
        return;
    }

    int maxLevelSum(TreeNode* root) {
        createDict(root);

        int max = INT_MIN, index = -1;
        for (auto item : maxSum) {
            if (max < item.second) {
                max = item.second;
                index = item.first;
            }
        }
        return index + 1;
    }
};
