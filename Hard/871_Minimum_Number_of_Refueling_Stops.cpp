//Greedy
//Runtime 24
//Memory Usage 16.1
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        priority_queue<int> q;
        int cur  = startFuel;
        for(const auto &st : stations){
            while(!q.empty() && cur < st[0] && cur < target)
                cur += q.top(), q.pop(), ++res;
            if(cur >= target)
                return res;
            if(cur < st[0])
                return -1;
            q.push(st[1]);
        }
        while(!q.empty() && cur < target)
            cur += q.top(), q.pop(), ++res;
        return cur >= target ? res : -1;
    }
};