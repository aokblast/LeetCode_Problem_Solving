//Greedy
//Runtime 121
//Memory Usage 10.2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<int> tmp = mat[0];
        vector<int> cur;

        for(int i = 1; i < n; ++i) {
            int t = tmp.size();

            for(int j = 0; j < m; ++j) 
                for(int k = 0; k < t; ++k)     
                    cur.push_back(mat[i][j] + tmp[k]);
            
            sort(cur.begin(), cur.end());

            tmp.clear();
            tmp.insert(tmp.end(), cur.begin(), cur.begin() + min(k, (int)cur.size()));

            cur.clear();
        }

        return tmp[k - 1];
        
    }
};