class MyCalendarThree {
private:
    map<int, int> mp;
public:
    int canAdd(int n) {
        int count = 0, temp_max = 0;
        for (auto item : mp) {
            count += item.second;
            temp_max = std::max(temp_max, count);
        }
        return temp_max;
    }

    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        return canAdd(2);
    }
};