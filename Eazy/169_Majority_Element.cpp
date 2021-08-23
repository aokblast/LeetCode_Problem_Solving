//hash_map
//Runtime 20 
//Memory Usage 19.7
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) ++m[i];
        for(auto i : m) if(i.second >= nums.size() / 2 + 1) return i.first;
        return 0;
    }
};
//moore voting
//Runtime 12
//Memory Usage 19.7
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, cnt = 0;
        for(int &num  :nums){
            if(!cnt){cand = num, ++cnt;}
            else cnt += cand == num ? 1 : -1;
        }
        return cand;
    }
};
