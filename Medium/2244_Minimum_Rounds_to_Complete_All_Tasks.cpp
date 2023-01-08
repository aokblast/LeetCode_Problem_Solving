//
//Runtime 513
//Memory Usage 103.6

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        
        for(const auto t : tasks)
            mp[t]++;

        int res = 0;

        for(const auto [_, cnt] : mp) 
            if(cnt != 1)
                res += (cnt + 2) / 3;
            else
                return -1;
        

        return res;
    }
};