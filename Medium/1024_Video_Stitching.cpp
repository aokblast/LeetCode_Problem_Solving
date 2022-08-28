//Greedy
//Runtime 0
//Memory Usage 7.9

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](const auto &c1, const auto &c2){return c1[0] == c2[0] ? c1[1] < c2[1] : c1[0] < c2[0];});
        int r = 0, res = 0, i = 0, n = clips.size();
        while(i < n && r < time){
            int cur = 0;
            
            if(clips[i][0] > r)
                return -1;
            
            for(; i < n && clips[i][0] <= r; ++i)
                cur = max(cur, clips[i][1]);
            
            r = cur;
            ++res;
        }
        return r >= time ? res : -1;
        
        
    }
};