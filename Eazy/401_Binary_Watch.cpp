//
//Runtime 0 
//Memory Usage 6.4
class Solution {
public:
    int cnt(int n){
        int ans = 0;
        for(;n; n &= n - 1, ++ans){}
        return ans;
    }
    
    vector<string> readBinaryWatch(int t) {
        vector<string> res;
        for(int i = 0; i < (1 << 10); ++i){
            if(cnt(i) != t) continue;
            int h = i & 0xf;
            int min = i >> 4;
            if(h < 12 && min < 60) res.push_back(to_string(h) + ":" + (min < 10 ? "0" : "" ) + to_string(min));
        }
        return res;
    }
};
