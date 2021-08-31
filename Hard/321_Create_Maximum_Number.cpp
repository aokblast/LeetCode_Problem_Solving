//
//Runtime 116
//Memory Usage 27.9
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        for(int i = max(0, k - n2); i <= min(k, n1); ++i){
            ans = max(ans, merge(getMax(nums1, i), getMax(nums2, k - i)));
        }
        return ans;
    }
    vector<int> getMax(vector<int> &nums , int n){
        int discard = nums.size() - n;
        vector<int> res;
        for(int &num : nums){
            while(discard && !res.empty() && res.back() < num) res.pop_back(), --discard;
            
            res.push_back(num);
        }
        res.resize(n);
        return res;
    }
    vector<int> merge(vector<int> a, vector<int> b){
        vector<int> res;
        while (!a.empty() || !b.empty()) {
            vector<int> &tmp = (a > b) ? a : b;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
    
};
