class MedianFinder {
private:
  priority_queue<int, vector<int>, greater<int>> large; // minHeap
  priority_queue<int> small;                            // maxHeap
  int size = 0;

public:
  MedianFinder() {}

  void addNum(int num) {
    small.push(num);
    if (!small.empty() && !large.empty() && small.top() > large.top()) {
      int val = small.top();
      small.pop();
      large.push(val);
    }

    if (small.size() > large.size() + 1) {
      int val = small.top();
      small.pop();
      large.push(val);
    }
    if (large.size() > small.size() + 1) {
      int val = large.top();
      large.pop();
      small.push(val);
    }
    size++;
  }

  double findMedian() {
    if (size % 2 == 0) {
      return (double)(large.top() + small.top()) / 2;
    } else {
      if (large.size() > small.size()) {
        return large.top();
      }
      if (small.size() > large.size())
        return small.top();
    }
  }
};
