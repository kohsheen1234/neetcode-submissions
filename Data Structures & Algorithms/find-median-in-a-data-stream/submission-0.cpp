class MedianFinder {
    priority_queue<int> small;                              // max-heap: smaller half
    priority_queue<int, vector<int>, greater<int>> large;   // min-heap: larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        // 1. push to small, 2. shift small's top into large
        small.push(num);
        large.push(small.top());
        small.pop();

        // 3. rebalance: keep small the same size or one bigger
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size())
            return small.top();                             // odd: extra lives in small
        return (small.top() + large.top()) / 2.0;           // even: average the two tops
    }
};