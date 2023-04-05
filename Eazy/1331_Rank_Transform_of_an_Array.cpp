//
//Runtime 77
//Memory Usage 35.1
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        for(int i = 0; i < n; ++i) 
            v.push_back({arr[i], i});
        
        sort(v.begin(), v.end());
        int cur = 0;
        int pre = -1;

        for(const auto [num, idx] : v)
            if(num == pre)
                arr[idx] = cur;
            else
                arr[idx] = ++cur, pre = num;
        
        return arr;
    }
};