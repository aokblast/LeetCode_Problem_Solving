//greedy
//Runtime 286
//Memory Usgae 104.1

class TopVotedCandidate {
public:
    int n;
    vector<pair<int, int>> vs;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> cnt;
        n = persons.size();
        for(int i = 0; i < n; ++i)
            vs.push_back({times[i], persons[i]});
        
        
        int mx = -1, num = 0;
        for(int i = 0; i < n; ++i){
            if(++cnt[vs[i].second] >= mx)
                mx = cnt[vs[i].second], num = vs[i].second;
            vs[i].second = num;
        }
        
        
    }
    
    int q(int t){
        auto iter =lower_bound(vs.begin(), vs.end(), make_pair(t, 0));
        if(iter->first == t)
            return iter->second;
        else
            return (--iter)->second;
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */