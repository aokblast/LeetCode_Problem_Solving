//Math
//Runtime 120
//Memory Usage 60.7

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int div[k];

        memset(div, 0, sizeof(div));

        for(const auto num : arr)
            div[(num % k + k) % k]++;
        
        for(int i = 1; i <= k / 2; ++i)
            if(div[i] != div[k - i])
                return false;

        return k % 2 == 0 ? (div[k / 2] % 2 == 0) : true;
    }
};