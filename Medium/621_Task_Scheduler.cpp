//
//Runtime 59
//Memory Usage 34.5


class Solution {
public:
    int cnt[26] = {0};
    int leastInterval(vector<char>& tasks, int n) {
        
        for(const char task : tasks) ++cnt[task - 'A'];
        int res = 0;
        sort(cnt, cnt + 26);
        int ma = cnt[25], i = 25;
        while(i >= 0 && cnt[i] == ma) --i;
        return max((int)tasks.size(), (ma - 1) * (n + 1) + 25 - i);
        
        
    }
};