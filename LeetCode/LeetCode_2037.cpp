class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int result = 0;
        for (size_t i = 0; i < seats.size(); i++) {
            result += seats[i] > students[i] ? seats[i] - students[i] : students[i] - seats[i];
        }

        return result;
    }
};