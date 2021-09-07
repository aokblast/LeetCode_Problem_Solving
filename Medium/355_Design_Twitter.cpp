//Priority_queue
//Runtime 0
//Memory Usage 7.2 
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        twt[userId].push_back({++cnt, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(const int &id : frd[userId]){
            for(pair<int, int> &arti : twt[id]){
                if(q.size() > 10 && q.top().first > arti.first && q.size() > 10) continue;
                q.push(arti);
                if(q.size() > 10)q.pop();
            }
        }
        vector<int> ans;
        while(!q.empty()) ans.push_back(q.top().second), q.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        frd[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)frd[followerId].erase(followeeId);
    }
    unordered_map<int, vector<pair<int, int>>> twt;
    unordered_map<int, unordered_set<int>> frd;
    int cnt = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
