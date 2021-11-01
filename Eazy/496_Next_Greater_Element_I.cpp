//Monotonic Stack
//Runtime 4
//Memory Usage 8.9
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums2.size();
        unordered_map<int, int> loc;
        stack<int> s;
        for(int &num : nums2){
            while(!s.empty() && s.top() < num){
                loc[s.top()] = num, s.pop();
            }
            s.push(num);
        }
        for(int &num : nums1)ans.push_back(((loc.find(num) != loc.end()) ? loc[num] : -1));
        return ans;
    }
};
