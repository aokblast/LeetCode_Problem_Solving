//greedy
//Runtime 17
//Memory Usage 13.1

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int res = INT_MAX;
        int j = 0;
        
        for(int i = 0; i < n; ++i){
            while(stones[i] - stones[j] >= n)
                ++j;
            int in = i - j + 1;
            
            if(in == n - 1 && stones[i] - stones[j] + 1 == n - 1)
                res = min(res, 2);
            else
                res = min(res, n - in);
        }
        
        return {res, max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - n + 2};
    }
};