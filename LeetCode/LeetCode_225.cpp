class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};