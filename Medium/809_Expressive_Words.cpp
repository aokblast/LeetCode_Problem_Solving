//
//Runtime 3
//Memory Usgae 7.5

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> v;
        for(int i = 0; i < s.size();){
            char c = s[i];
            int cnt = 0;
            while(i + cnt < s.size() && c == s[i + cnt])
                ++cnt;
            v.push_back({c, cnt});
            i += cnt;
        }
        int res = 0;
        for(const auto &word : words){
            int idx = 0;
            bool ans = true;
            for(int i = 0; i < word.size();){
                if(idx == v.size()){
                    ans = false;
                    break;
                }
                char c = word[i];
                if(c != v[idx].first){
                    ans = false;
                    break;
                }
                
                int cnt = 0;
                while((i + cnt) < word.size() && c == word[i + cnt])
                    ++cnt;
                if((v[idx].second <= 2 && v[idx].second != cnt) || (v[idx].second > 2 && v[idx].second < cnt) ){
                    ans = false;
                    break;
                }
                i += cnt;
                ++idx;
            }
            res += ans && idx == v.size();
        }
        return res;
        
    }
};