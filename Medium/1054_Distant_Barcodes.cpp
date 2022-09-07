//Greedy
//Runtime 97
//Memory 37.4
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int mp[10005] = {0};
        
        for(const int code : barcodes)
            mp[code]++;

        int n = barcodes.size();
        
        vector<int> res(n);
        vector<pair<int, int>> v;
        
        
    
        
        for(int i = 0; i <= 10000; ++i)
            if(mp[i])
                v.push_back({mp[i], i});
        
        sort(v.begin(), v.end(), greater());
        
        int i = 0;
        
        for(auto [cnt, num] : v) {
            while(cnt) {
                res[i] = num;
                --cnt;
                i += 2;
                if(i == n + 1 || i == n)
                    i = 1;
            }   
        }
        return res;
        
        
    }
};