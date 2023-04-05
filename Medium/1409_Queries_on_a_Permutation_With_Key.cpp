//
//Runtime 3
//Memory Usage 8.2

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m);

        for(int i = 0; i < m; ++i) 
            v[i] = m - i;

        vector<int> res;

        for(const auto q : queries) {
            auto cur = find(v.begin(), v.end(), q);
            v.erase(cur);
            v.push_back(q);

            res.push_back(m - (cur - v.begin()) - 1);
        }
        
        return res;
    }
};