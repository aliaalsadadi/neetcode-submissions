class Twitter {
private:
  unordered_map<int, unordered_set<int>> followMap;
  unordered_map<int, vector<pair<int, int>>> posts; // userId, [(count,tweetId )]
  int count;

public:
  Twitter() { count = 0; }

  void postTweet(int userId, int tweetId) {
    posts[userId].push_back({count, tweetId});
    count++;
  }

  vector<int> getNewsFeed(int userId) {

    vector<pair<int, int>> news;
    for (const auto& f : followMap[userId]) {
      news.insert(news.end(), posts[f].begin(), posts[f].end());
    }
    news.insert(news.end(), posts[userId].begin(), posts[userId].end());
    priority_queue<pair<int, int>> pq(news.begin(), news.end());
    vector<int> res;
    for (int i = 0; i < 10; i++) {
      if (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
      }
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    followMap[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    followMap[followerId].erase(followeeId);
  }
};

