//
//Runtime 242
//Memory Usage 32

class Solution {
public:
    static const int MAXN = 1e5 + 5;
    int p[MAXN] = {0};
    int sz[MAXN] = {0};
    int find(int u){
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    int largestComponentSize(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 1e5 + 5; ++i)
            p[i] = i;
        
        for(const int num : nums){
            int lim = sqrt(num);
            for(int i = 2; i <= lim; ++i){
                if(num % i == 0){
                    int p1 = find(num), p2 = find(i);
                    p[p2] = p1;
                    p2 = find(num / i);
                    p[p2] = p1;
                }
            }
        }
        for(const int num : nums)
            res = max(res, ++sz[find(num)]);
        return res;
    }
};