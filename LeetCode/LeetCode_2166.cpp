class Bitset {
    string arr, inv;
    int size, counter;
public:
    Bitset(int size) {
        arr.resize(size, '0');
        inv.resize(size, '1');
        this->size = size;
        counter = 0;
    }

    void fix(int idx) {
        if (arr[idx] == '0')
            counter++;
        arr[idx] = '1';
        inv[idx] = '0';
    }

    void unfix(int idx) {
        if (arr[idx] == '1')
            counter--;
        arr[idx] = '0';
        inv[idx] = '1';
    }

    void flip() {
        swap(arr, inv);
        counter = size - counter;
    }

    bool all() {
        return counter == size;
    }

    bool one() {
        return counter > 0;
    }

    int count() {
        return counter;
    }

    string toString() {
        return arr;
    }
};
