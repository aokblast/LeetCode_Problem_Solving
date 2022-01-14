//DFS
//Runtime 23
//Memory Usage 10.9

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size(), i;
        for(i = 0; i < n; ++i)res += price[i] * needs[i];
        for(const auto & offer : special){
            bool isValid = true;
            for(i = 0; i < n; ++i){
                if(needs[i] - offer[i] >= 0){needs[i] -= offer[i];}
                else{isValid = false;break;}
                
            }
            if(isValid)
                res = min(res, shoppingOffers(price, special, needs) + offer.back());
            for(int j = 0; j < i; ++j)needs[j] += offer[j];
        }
        return res;
        
        
    }
};