//
//Runtime 88
//Memory Usage 38.2

class TweetCounts {
private:
    unordered_map<string, vector<int>> mp;
    unordered_map<string, int> time = {{"minute", 60}, {"hour", 3600}, {"day", 14400}};
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = time[freq];

        int tot = (endTime - startTime) / delta + 1;
        vector<int> ans(tot);

        for(const auto t : mp[tweetName])
            if(t >= startTime && t <= endTime)
                ans[(t - startTime) / delta]++;
        
        return ans;
        
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */