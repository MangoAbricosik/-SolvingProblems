class Solution {
	void dfs(TreeNode* root, vector<string>& result, string temp) {
		if (!root)
			return;

		temp += to_string(root->val);

		if (!root->left && !root->right) {
			result.push_back(temp);
			return;
		}

		temp += "->";

		if (root->left)
			dfs(root->left, result, temp);
		if (root->right)
			dfs(root->right, result, temp);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		string temp = "";
		vector<string> result;
		dfs(root, result, temp);
		return result;
	}
};