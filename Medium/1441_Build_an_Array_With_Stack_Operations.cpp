//
//Runtime 0
//Memory Usage 7.7

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        int cur = 0;

        for (const auto t : target) {
            int cnt = t - cur - 1;

            for(int i = 0; i < cnt; ++i)
                res.push_back("Push");

            for(int i = 0; i < cnt; ++i)
                res.push_back("Pop");

            res.push_back("Push");

            cur = t;
            
        }

        return res;
    }
};