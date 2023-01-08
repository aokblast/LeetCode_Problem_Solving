//
//Runtime 597
//Memory 80.8
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        auto getMask = [&](const string &s) {
            int mask = 0;
            
            for(const char c : s)
                mask |= (1 << (c - 'a'));
            
            return mask;
        };
        
        unordered_map<int, int> mp;
        
        for(const auto &word : words)
            mp[getMask(word)]++;
        
        vector<int> res;
        
        for(const auto &puzzle : puzzles) {
            int cur = getMask(puzzle), tot = cur, cnt = 0, first = 1 << (puzzle[0] - 'a');
            for(; cur; cur = (cur - 1) & tot)
                if(cur & first)
                    cnt += mp[cur];
           
            res.push_back(cnt);
        }
        
        return res;
    }
};