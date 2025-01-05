class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		string arr = to_string(k);
		vector<int> toAdd;
		for (size_t i = 0; i < arr.size(); i++) {
			toAdd.push_back(arr[i] - 48);
		}
		reverse(toAdd.begin(), toAdd.end());

		int to_much = 0;
		reverse(num.begin(), num.end());

		auto it_num = num.begin();
		auto it_toAdd = toAdd.begin();

		vector<int> result;
		while (it_num != num.end() || it_toAdd != toAdd.end() || to_much > 0) {
			int val = it_num != num.end() ? *it_num : 0;
			int add = it_toAdd != toAdd.end() ? *it_toAdd : 0;

			int temp = val + add + to_much;
			to_much = 0;
			if (temp > 9) {
				to_much += temp / 10;
				temp %= 10;
			}

			result.push_back(temp);

			if (it_num != num.end())
				it_num++;
			if (it_toAdd != toAdd.end())
				it_toAdd++;
		}

		reverse(result.begin(), result.end());
		return result;
	}
};