//
//Runtime 4
//Memory Usage 8.3

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        for(int i = 2; i < n; ++i) 
            if((arr[i - 2] % 2) && (arr[i - 1] % 2) && (arr[i] % 2))
                return true;
        
        return false;
    }
};