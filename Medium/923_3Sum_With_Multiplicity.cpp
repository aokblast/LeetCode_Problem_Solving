//
//Runtime 20
//Memory Usage 10.6

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long> cnt;
        int n = arr.size();
        long res = 0;
        for(const int num : arr)
            cnt[num]++;
        for(const auto [num1, cnt1] : cnt){
            for(const auto [num2, cnt2] : cnt){
                int num3 = target - num1 - num2;
                if(cnt.find(num3) == cnt.end())
                    continue;
                if(num1 == num2 && num2 == num3)
                    res += cnt1  * (cnt2 - 1) * (cnt1 - 2) / 6;
                else if(num1 == num2 && num2 != num3)
                    res += cnt1 * (cnt1 - 1) / 2 * cnt[num3];
                else if(num1 < num2 && num2 < num3)
                    res += cnt1 * cnt2 * cnt[num3];
            }
        }
        return res % MOD;
    }
};