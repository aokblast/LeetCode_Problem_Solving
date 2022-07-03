//Greedy
//Runtime 8
//Memory Usage 10.5

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        if(n == 0)
            return 0;
        int res = 0;
        int l = 0, r = n - 1;
        while(l < r){
            if(power >= tokens[l]){
                ++res;
                power -= tokens[l++];
            }else if(res){
                --res;
                power += tokens[r--];
            }else{
                return 0;
            }
        }
        if(power >= tokens[r])
            ++res;
        
        return res;
    }
};