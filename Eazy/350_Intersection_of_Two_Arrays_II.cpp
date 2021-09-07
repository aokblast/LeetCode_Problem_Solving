//
//Runtime 4
//Memory Usage 10.1 
class Solution {
public:
    int set[1005] = {0};
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int &n : nums1){
            ++set[n];
        }
        for(int &n : nums2){
            if(set[n]-- > 0){
                res.push_back(n);
            }
        }
        return res;
    }
};
