//prefix XOR
//Runtime 85
//Memory Usage 38.2


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int p[n];
        
        p[0] = arr[0];
        
        for(int i = 1; i < n; ++i)
            p[i] = p[i - 1] ^ arr[i];

        vector<int> res;

        for(const auto &q : queries) {
            int cur = p[q[1]];
            if(q[0] > 0)
                cur ^= p[q[0] - 1];
            res.push_back(cur);
        }

        return res;
    }
};