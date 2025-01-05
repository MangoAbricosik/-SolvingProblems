class Solution {
public:
	string addStrings(string num1, string num2) {
		vector<int> toAdd;
		for (size_t i = 0; i < num2.size(); i++) {
			toAdd.push_back(num2[i] - 48);
		}
		reverse(toAdd.begin(), toAdd.end());

		int to_much = 0;
		vector<int> num;
		for (size_t i = 0; i < num1.size(); i++) {
			num.push_back(num1[i] - 48);
		}
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
		string strResult;
		for (auto item : result)
			strResult += char(item) + '0';
		return strResult;
	}
};