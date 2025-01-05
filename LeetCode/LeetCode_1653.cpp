class OrderedStream {
public:
    OrderedStream(int n) {
        full.resize(n);
        it = full.begin();
    }

    vector<string> insert(int idKey, string value) {
        full[--idKey] = value;

        vector<string> temp;
        while (it != full.end() && *it != "") {
            temp.push_back(*it);
            it++;
        }
        return temp;
    }
private:
    vector<string> full;
    vector<string>::iterator it;
};
