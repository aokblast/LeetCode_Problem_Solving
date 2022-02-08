//
//Runtime 4
//Memory Usage 12,7
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(const auto &word : words)
            ++freq[word];
        
        vector<pair<int, string>> v;
        for(const auto &[word, f] : freq)
            v.push_back({f, word});
        
        sort(v.begin(), v.end(), [](const auto &p1, const auto &p2){return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;});
        vector<string> res;
        int t = v.size() - 1;
        while(k--){
            res.push_back(v[t--].second);
        }
        return res;
    }
};