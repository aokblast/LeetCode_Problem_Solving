//
//Runtime 58
//Memory Usage 32.4

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3)
            return false;
        
        sum /= 3;
        int cur = 0, cnt = 0;
        
        for(const int num : arr){
            cur += num;
            if(cur == sum){
                ++cnt, cur = 0;
                if(cnt == 3)
                    return true;
            }
        }
        return false;
        
    }
};