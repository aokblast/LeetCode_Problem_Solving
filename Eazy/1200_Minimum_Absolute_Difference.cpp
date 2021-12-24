//
//Runtime 60
//Memory Usage 32.2
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int k = INT_MAX, n = arr.size();
        for(int i = 1; i < n; ++i){
            k = min(k, abs(arr[i] - arr[i - 1]));
        }
        vector<vector<int>> res;
        for(int i = 1; i < n; ++i){
            if(arr[i] - arr[i - 1] == k)res.push_back({arr[i - 1], arr[i]});      
        }
        return res;
        
    }
};