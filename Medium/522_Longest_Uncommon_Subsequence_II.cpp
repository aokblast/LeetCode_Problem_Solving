//
//Runtime 0
//Memory Usage 8.4
class Solution {
public:
    
    int findLUSlength(vector<string>& strs) {
        int ans = -1, n = strs.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j)continue;
                int k = 0;
                for(int l = 0; k < strs[i].length() && l < strs[j].length() ; k += strs[i][k] == strs[j][l], ++l);
                if(k == strs[i].length())goto start;
            }
            ans = max(ans, (int)strs[i].size());
            start:
            1;
        }
        return ans;
    }
};
