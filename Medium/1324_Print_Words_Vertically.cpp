//
//Runtime 0
//Memory Usage 6.3

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;

        stringstream ss(s);

        string cur;
        int mx = 0;
        int c = 0;

        while(ss >> cur) {
            int n = cur.size();

            for(; mx < n; ++mx)
                res.emplace_back(string(c, ' '));

            for(int i = 0; i < n; ++i) {
            
                while(res[i].size() < c)
                    res[i].push_back(' ');
                    
                res[i].push_back(cur[i]);
            }
        
            ++c;
        }

        return res;
    }
};