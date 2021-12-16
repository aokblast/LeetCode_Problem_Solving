//dp
//Runtime 7
//Memory Usage 6.9

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> now(m + 1), prev(m + 1);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    now[j] = prev[j - 1] + 1;
                }else{
                    now[j] = max(prev[j], now[j - 1]);
                }
            }
            prev = now;
        }
        return n + m - 2 * (now[m]);
    }
};