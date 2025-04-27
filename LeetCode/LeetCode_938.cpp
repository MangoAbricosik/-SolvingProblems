 class Solution {
     int sum = 0;
 public:
     int rangeSumBST(TreeNode* root, int low, int high) {
         if (!root)
             return 0;
         sum += (root->val >= low && root->val <= high ? root->val : 0);
         rangeSumBST(root->left, low, high);
         rangeSumBST(root->right, low, high);
         return sum;
     }
 };