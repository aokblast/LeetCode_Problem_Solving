//
//Runtime 0
//Memory Usage 6.7
class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            int cnt = 1;
            while(s[++i] == c){
                ++cnt;
            }
            --i;
            res = max(res, cnt);
        }
        return res;
    }
};