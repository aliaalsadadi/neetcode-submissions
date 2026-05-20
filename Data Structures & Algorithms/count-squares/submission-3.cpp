class CountSquares {
private:
  struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
      size_t a = hash<int>{}(p.first);
      size_t b = hash<int>{}(p.second);
      return a ^ (b << 1);
    }
  };
  unordered_map<pair<int, int>, int, pair_hash> plot;

public:
  CountSquares() {}

  void add(vector<int> point) { plot[{point[0], point[1]}]++; }

  int count(vector<int> point) {
    int res = 0;
    for (const auto& [p, c] : plot) {
      int x = p.first, y = p.second;
      int dx = abs(x - point[0]);
      int dy = abs(y - point[1]);
      if (dx != dy || dx == 0)
        continue;
      if (plot.count({x, point[1]}) && plot.count({point[0], y})) {
        res += c * plot[{x, point[1]}] * plot[{point[0], y}];
      }
    }
    return res;
  }

};
