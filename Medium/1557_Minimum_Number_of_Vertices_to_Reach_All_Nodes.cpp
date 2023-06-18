//
//Runtime 294
//Memory Usage 93.8

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool s1[n], s2[n];
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        for(const auto &edge : edges) {
            s1[edge[0]] = true;
            s2[edge[1]] = true;
        }

        vector<int> res;

        for(int i = 0; i < n; ++i) {
            if(s1[i] && !s2[i])
                res.push_back(i);
        }

        return res;
    }
};