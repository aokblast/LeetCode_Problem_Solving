//hash table
//Runtime 4 
//Memory Usage 10
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m;
        for(auto &n : nums){
            m[n]++;
        }
        for(auto &n : m){
            if(n.second == 1){
                ans = n.first;
                break;
            }
        }
        return ans;
    }
};
