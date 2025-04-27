class Solution {
	void dfs(TreeNode* root, int& level, vector<priority_queue<int>>& pq) {
		level++;
		if (level < pq.size())
			pq[level].push(root->val);
		else {
			priority_queue<int> temp;
			temp.push(root->val);
			pq.push_back(temp);
		}
		if (root->left)
			dfs(root->left, level, pq);
		if (root->right)
			dfs(root->right, level, pq);
		level--;
	}
public:
	vector<int> largestValues(TreeNode* root) {
		int level = -1;
		vector<priority_queue<int>> pq;
		if (root)
			dfs(root, level, pq);

		vector<int> result;
		for (auto item : pq) {
			if (!item.empty())
				result.push_back(item.top());
		}
		return result;
	}
};