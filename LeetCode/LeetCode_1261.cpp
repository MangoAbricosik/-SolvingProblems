class FindElements {
	set<int> st;
	void createTree(TreeNode* root, int prev) {
		if (root->left) {
			root->left->val = 2 * prev + 1;
			st.insert(root->left->val);
			createTree(root->left, root->left->val);
		}
		if (root->right) {
			root->right->val = 2 * prev + 2;
			st.insert(root->right->val);
			createTree(root->right, root->right->val);
		}
	}
public:
	FindElements(TreeNode* root) {
		root->val = 0;
		st.insert(0);
		createTree(root, 0);
	}

	bool find(int target) {
		if (st.find(target) != st.end())
			return true;
		return false;
	}
};