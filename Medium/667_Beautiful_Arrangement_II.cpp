//
//Runtime 0
//Memory Usage 7.6

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1, r = n;
        while(l <= r)
            res.push_back(k >= 1 ? (k-- % 2 ? l++ : r--) : l++);
        return res;
    }
};