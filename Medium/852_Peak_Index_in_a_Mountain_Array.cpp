//
//Runtime 10
//Memory Usage 11.6

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();


    }
};