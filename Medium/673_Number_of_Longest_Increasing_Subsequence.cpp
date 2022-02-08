//BIT
//Runtime 12
//Memory Usage 13.2


class Solution {
public:
    int n;
    pair<int, int> tree[2005] = {{0, 0}};
    void update(int idx, int val, int len){
        for(; idx <= n; idx += idx & (-idx)){
            if(tree[idx].first == len){
                tree[idx].second += val;
            }else if(tree[idx].first < len){
                tree[idx].second = val;
                tree[idx].first = len;
            }
        }
        
    }
    pair<int, int> get(int idx){
        pair<int, int> res;
        for(; idx > 0; idx -= idx & (-idx)){
            if(tree[idx].first > res.first)
                res = tree[idx];
            else if(tree[idx].first == res.first)
                res.second += tree[idx].second;
        }
        return res;
    }
    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i)
            a[i] = nums[i - 1];
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
        int ma = 0, res = 0;
        for(int i = 1; i <= n; ++i){
            auto [len, cnt] = get(a[i] - 1);
            if(len == 0)
                cnt = 1;
            update(a[i], cnt, ++len);
            
        }
        return get(n).second;
    }
};