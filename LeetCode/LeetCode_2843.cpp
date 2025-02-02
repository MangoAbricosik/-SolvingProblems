class Solution {
public:
	int countSymmetricIntegers(int low, int high) {
		int counter = 0;
		for (size_t i = low; i <= high; i++) {
			string temp = to_string(i);
			if (temp.size() < 2 || temp.size() % 2 == 1)
				continue;

			int first = 0, second = 0;
			for (size_t i = 0; i < (temp.size() / 2); i++) {
				first += int(temp[i] - '0');
			}

			for (size_t i = (temp.size() / 2); i < temp.size(); i++) {
				second += int(temp[i] - '0');
			}

			if (first == second)
				counter++;
		}
		return counter;
	}
};