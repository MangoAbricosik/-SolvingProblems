class Solution {
public:
	TreeNode* dfs(TreeNode* curr, int val) {
		if (!curr) return NULL;
		if (curr->val == val) return curr;
		TreeNode* l = dfs(curr->left, val);
		if (l) return l;
		TreeNode* r = dfs(curr->right, val);
		if (r) return r;
		return NULL;
	}

	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		int val = target->val;
		return dfs(cloned, val);
	}
};