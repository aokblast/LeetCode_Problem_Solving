//
//Runtime 0
//Memory Usage 6.7

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for(const char c : s)
            ++cnt1[c - 'a'];
        int l = 0, r = 0, cnt = 0;
        int n = s.size();
        vector<int> res;
        while(r < n){
            memset(cnt2, 0, sizeof(cnt2));
            do{
                char c = s[r];
                ++cnt2[c - 'a'];
                if(cnt2[c - 'a'] == 1)
                    ++cnt;
                if(cnt2[c - 'a'] == cnt1[c - 'a'])
                    --cnt;
                ++r;
            }while(r < n && cnt);
                
            res.push_back(r - l);
            l = r;  
        }
        return res;
    }
};