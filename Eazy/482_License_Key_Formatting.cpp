//
//Runtime 8 
//Memory Usage 8.3
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        int cnt = 0;
        string ans;
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '-')continue;
            ans += toupper(s[i]);
            if((cnt++)  % k == k - 1){
                ans += '-';
            }
        }
        if(!(cnt % k) && ans.size())ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
