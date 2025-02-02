class MyCalendarTwo {
private:
    map<int, int> mp;
public:
    bool canAdd(int n) {
        int count = 0;
        for (auto item : mp) {
            count += item.second;
            if (count > n)
                return false;
        }
        return true;
    }

    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        if (canAdd(2))
            return true;
        else {
            mp[start]--;
            mp[end]++;
            return false;
        }
    }
};