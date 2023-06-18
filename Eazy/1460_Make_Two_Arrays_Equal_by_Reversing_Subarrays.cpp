//
//Runtime 7
//Memory Usage 14.6

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnts[1005] = {0}, n = target.size();

        for(int i = 0; i < n; ++i)
            cnts[target[i]]++, cnts[arr[i]]--;

        for(const int cnt : cnts)
            if(cnt)
                return false;
        
        return true;
    }
};