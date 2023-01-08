//Greedy
//Runtime 197
//Memory Usage 84.8


class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        
        for(int i = 0; i < n; ++i) 
            capacity[i] -= rocks[i];
        
        sort(capacity.begin(), capacity.end());
        int idx = upper_bound(capacity.begin(), capacity.end(), 0) - capacity.begin();
        
        while(idx < n && additionalRocks > 0)
            additionalRocks -= capacity[idx], ++idx;
        
        return idx - (additionalRocks < 0);      
    }
};