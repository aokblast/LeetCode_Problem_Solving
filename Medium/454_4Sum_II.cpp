//unordered_map
//Runtime 168
//Memory Usage 24.2
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> count;
        for(int &a : nums1){
            for(int &b : nums2){
                ++count[a + b];
            }
        }
        int ans = 0;
        for(int &a : nums3){
            for(int &b : nums4){
                auto it = count.find(-a - b);
                if(it != count.end()){
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};
