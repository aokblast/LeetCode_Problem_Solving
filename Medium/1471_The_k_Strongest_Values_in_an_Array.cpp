//
//Runtime 196
//Memory Usage 82.8

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int sz = arr.size(), i = 0, j = sz - 1;
        int mid = arr[(sz - 1) / 2];
        vector<int> res;

        while(k--) {
            if((mid - arr[i]) > (arr[j] - mid))
                res.push_back(arr[i++]);
            else
                res.push_back(arr[j--]);
        }

        return res;
    }
};