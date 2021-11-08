//
//Runtime 8
//Memory Usage 13
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int avg = accumulate(machines.begin(), machines.end(), 0), n = machines.size();
        
        if(avg % n)return -1;
        avg /= n;
        int ans = 0, cnt = 0;
        for(const int &num : machines){
            cnt += num - avg;
            ans = max(ans, max(abs(cnt), num - avg));
        }
        return ans;
        
    }
};