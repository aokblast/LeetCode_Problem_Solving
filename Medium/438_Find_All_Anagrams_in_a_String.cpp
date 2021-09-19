//
//Runtime 4
//Memory Usage 8.5
class Solution {
public:
    int ma[26] = {0};
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int cnt = 0;
        for(char &c : p){
            ++ma[c - 'a'];
            cnt += (ma[c - 'a'] == 1);
        }
        int n = p.size(), m = s.size();
        int l = 0, r = 0;
        while(r < m){
            while(r < m && (r - l)< n){
                cnt -= (!(--(ma[s[r++] - 'a'])));
            }
            if(!cnt){
                ans.push_back(l);
            }
            if(!(ma[s[l++] - 'a']++))++cnt;
        }
        return ans;
    }
    
};
