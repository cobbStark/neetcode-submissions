class Twitter {
    vector<vector<int>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp;
public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=0;
        vector<int> out;
        for(int i=tweets.size()-1; i>=0; i--)
        {
            if(tweets[i][0]==userId||following[userId].contains(tweets[i][0]))
            {
                ++count;
                out.push_back(tweets[i][1]);
                if(count==10)
                break;
            }
        }
        return out;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
