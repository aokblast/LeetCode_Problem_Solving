//
//Runtime 16 
//Memory Usage 17.8
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        for(int i = 0; i < n - 1; ++i){
            if(ratings[i] < ratings[i + 1]) candy[i + 1]  = candy[i] + 1;
        }
        for(int i = n - 1; i > 0; --i){
            if(ratings[i - 1] > ratings[i]) candy[i - 1] = max(candy[i - 1], candy[i] + 1);
        }
        int ans = 0;
        for(auto &n : candy){
            ans += n;
        }
        return ans;
    }
};
