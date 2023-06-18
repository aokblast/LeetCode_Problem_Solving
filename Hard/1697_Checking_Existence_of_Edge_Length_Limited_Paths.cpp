//Greedy
//Runtime 653
//Memory Usage 109.2

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int djs[n];

        memset(djs, 0, sizeof(djs));

        function<int(int)> pa = [&](int u) {
            return u == djs[u] ? u : djs[u] = pa(djs[u]);
        };

        for(int i = 0; i < n; ++i)
            djs[i] = i;

        int m = queries.size();
        for(int i = 0; i < m; ++i)
            queries[i].emplace_back(i);
        
        vector<bool> res(m);

        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {return lhs[2] < rhs[2];};

        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);

        int j = 0;

        for(int i = 0; i < m; ++i) {
            while(j < edgeList.size() && edgeList[j][2] < queries[i][2])
                djs[pa(edgeList[j][0])] = pa(edgeList[j][1]), ++j;
            
            res[queries[i][3]] = pa(queries[i][0]) == pa(queries[i][1]);
        }

        return res;
    }
};