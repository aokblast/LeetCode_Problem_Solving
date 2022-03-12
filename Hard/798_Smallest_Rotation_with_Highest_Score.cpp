//
//Runtime 116
//Memory Usage 72

class Solution {
public:
    int bestRotation(vector<int>& a) {
        int n = a.size();
        int ps[n + 5];
        memset(ps, 0, sizeof(ps));
        auto add = [&](int l, int r){
            ps[l]++; ps[r + 1]--;
        };
        for(int i = 0; i < n; ++i){
            if(a[i] <= i){
                add(0,  i - a[i]);
                add(i + 1, n - 1);
            }else{
                add(i + 1, n - a[i] + i);
            }
        }
        int mx = 0;
        int cur = 0, k = 0;
        for(int i = 0; i < n; ++i){
            cur += ps[i];
            if(cur > mx){
                cur = mx;
                k = i;
            }
        }
        return k;
        
    }
};