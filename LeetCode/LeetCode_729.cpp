class MyCalendar {
private:
    vector<pair<int, int>> vec;
public:
    MyCalendar() {

    }

    bool book(int startTime, int endTime) {
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[i].first < endTime && startTime < vec[i].second)
                return false;
        }
        vec.push_back(make_pair(startTime, endTime));
        return true;
    }
};