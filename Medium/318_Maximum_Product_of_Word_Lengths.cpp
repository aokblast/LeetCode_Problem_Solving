//Status Compression
//Runtime 28
//Memory Usage 15.4
class Solution {
public:
    int st[1005] = {0};
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i =0; i  < n; ++i){
            for(char &c : words[i]){
                st[i] |= (1 << (c - 'a'));
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!(st[i] & st[j])){
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;

    }
};
