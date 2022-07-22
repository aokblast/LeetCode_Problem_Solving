//
//Runtime 38
//Memory Usage 28.7

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int idx = num.size() - 1;
        vector<int> res;
        while(idx >= 0){
            num[idx] += k;
            k = num[idx] / 10;
            res.emplace_back(num[idx] % 10);
            --idx;
        }

        while(k)
            res.emplace_back(k % 10), k /= 10;
        reverse(res.begin(), res.end());
        return res;
    }
};