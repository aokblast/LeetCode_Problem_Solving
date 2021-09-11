//hash_map
//Runtime 20
//Memory Usage 10.6
class Solution {
public:
    int cnt[26] = {0};
    int firstUniqChar(string s) {
        for(int i = 0; i < s.size(); ++i){
            if(cnt[s[i] - 'a'])cnt[s[i] - 'a'] = INT_MAX;
            else cnt[s[i] - 'a'] = i + 1;
        }
        int ans = INT_MAX;
        for(int &i : cnt) if(i)ans = min(ans, i - 1);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};
