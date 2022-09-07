//Greedy
//Runtime 37
//Memory 24.7
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        map<int, int> mp;
        
        
        for(int i = arr.size() - 1; i + 1; --i) {
            auto iter = mp.lower_bound(arr[i]);
            if(iter != mp.begin()) {
                swap(arr[i], arr[(--iter)->second]);
                break;
            }
            mp[arr[i]] = i; 
        }
        return arr;
    }
};