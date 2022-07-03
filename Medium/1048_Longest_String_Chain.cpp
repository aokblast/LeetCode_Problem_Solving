//dp
//Runtime 46
//Memory Usage 12.7

class Solution {
public:
    int pre[1005] = {0};
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        sort(words.begin(), words.end(), [](const auto &w1, const auto &w2){
            return w1.size() < w2.size();
        });
        
        int res = 0;
        for(int i = 0; i < n - 1; ++i){
            string &s1 = words[i];
            for(int j = i + 1; j < n; ++j){
                string &s2 = words[j];
                if(s2.size() == s1.size())
                    continue;
                if(s2.size() > s1.size() + 1)
                    break;
                int diff = 0;
                int a = 0, b = 0;
                while(a < s1.size() && b < s2.size()){
                    diff += (s2[b] != s1[a] ? (++b, 1) : (++a, ++b, 0));
                    if(diff > 1)
                        break;
                }
                diff += b == (s2.size() - 1);
                if(diff == 1)
                    pre[j] = max(pre[j], pre[i] + 1), res = max(res, pre[j]);
            } 

             
        }
        return res + 1;
    }
};