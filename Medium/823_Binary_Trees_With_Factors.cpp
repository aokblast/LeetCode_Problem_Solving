//dp
//Runtime 52
//Memory Usage 9.3


class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long res = 0;
        unordered_map<int, long> mp;
        sort(arr.begin(), arr.end());
        const long MOD = 1e9 + 7;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            long num = arr[i];
            for(int j = 0; j < i; ++j){
                long n2 = arr[j];
                if(num % n2 == 0 && mp.find(num / n2) != mp.end()){
                    long cur = (mp[n2] * mp[num / n2]) % MOD;
                    mp[num] = (mp[num] + cur) % MOD;
                }
            }
            ++mp[num];

            res = (res + mp[num]) % MOD;
        }
        return res;
    }
};