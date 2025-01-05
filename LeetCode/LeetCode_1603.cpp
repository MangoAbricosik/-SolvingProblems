class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        mp[1] = big;
        mp[2] = medium;
        mp[3] = small;
    }

    bool addCar(int carType) {
        if (mp[carType] > 0) {
            mp[carType]--;
            return true;
        }
        return false;
    }
private:
    map<int, int> mp;
};