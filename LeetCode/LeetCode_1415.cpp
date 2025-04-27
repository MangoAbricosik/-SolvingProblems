class Solution {
	void getAset(set<string>& st, int& n, string& temp) {
		if (temp.size() == n) {
			st.insert(temp);
			temp.erase(temp.end() - 1);
			return;
		}

		if (temp.empty() || *(temp.end() - 1) != 'a') {
			temp.push_back('a');
			getAset(st, n, temp);
		}
		if (temp.empty() || *(temp.end() - 1) != 'b') {
			temp.push_back('b');
			getAset(st, n, temp);
		}
		if (temp.empty() || *(temp.end() - 1) != 'c') {
			temp.push_back('c');
			getAset(st, n, temp);
		}
		if (!temp.empty())
			temp.erase(temp.end() - 1);
		return;


	}
public:
	string getHappyString(int n, int k) {
		set<string> st;
		string a = "";
		getAset(st, n, a);
		if (k <= st.size()) {
			auto it = st.begin();
			for (size_t i = 0; i < k - 1; i++) {
				it++;
			}
			return *it;
		}
		return "";
	}
};