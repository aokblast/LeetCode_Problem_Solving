//
//Runtime 176
//Memory Usage 48.2

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> locs[26];
        for(int i = 0; i < s.size(); ++i)
            locs[s[i] - 'a'].push_back(i);
        int res = 0;
        for(const string &word : words){
            int i = -1, j = 0;
            while(true){
                const auto &loc = locs[word[j] - 'a'];
                const auto iter = upper_bound(loc.begin(), loc.end(), i);
                if(iter == loc.end())
                    break;
                ++j;
                i = *iter;
                if(j == word.size()){
                    ++res;
                    break;
                }
                
            }
        }
        return res;
    }
};