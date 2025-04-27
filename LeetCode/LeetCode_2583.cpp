class Solution {
	void dfs(TreeNode* root, int& level, vector<long long>& pq) {
		level++;
		if (level < pq.size())
			pq[level] += root->val;
		else {
			int temp = root->val;
			pq.push_back(temp);
		}
		if (root->left)
			dfs(root->left, level, pq);
		if (root->right)
			dfs(root->right, level, pq);
		level--;
	}
public:
	long long kthLargestLevelSum(TreeNode* root, int k) {
		int level = -1;
		vector<long long> pq;
		if (root)
			dfs(root, level, pq);
		sort(pq.rbegin(), pq.rend());
		if (k <= pq.size())
			return pq[--k];
		return -1;
	}
};