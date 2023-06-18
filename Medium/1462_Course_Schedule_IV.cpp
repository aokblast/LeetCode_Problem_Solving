//
//Runtime 167
//Memory Usage 58.9

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites
    , vector<vector<int>>& queries) {
        bitset<100> dp[numCourses], mask(1);

        for(const auto &pr : prerequisites) 
            dp[pr[0]][pr[1]] = 1;
        
        for(int k = 0; k < numCourses; ++k, mask <<= 1) {
            for(int i = 0; i < numCourses; ++i) {
                if((dp[i] & mask).any())
                    dp[i] |= dp[k];
            }
        }
        
        vector<bool> res;

        for(const auto &q : queries)
            res.emplace_back(dp[q[0]][q[1]]);

        return res;
    }
};