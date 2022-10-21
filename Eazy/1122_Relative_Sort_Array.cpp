//
//Runtime 3
//Memory Usage 7.7
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int idx = 0;
        map<int, int> mp;
        for(const int num : arr1)
            ++mp[num];
        
        for(const auto num : arr2)
            while(mp[num])
                --mp[num], arr1[idx++] = num; 
        
        for(auto [num, cnt] : mp)
            while(cnt--)
                arr1[idx++] = num;
        
        return arr1;
        
        
    }
};