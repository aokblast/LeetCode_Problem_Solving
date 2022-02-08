//
//Runtime 20
//Memory 12.3
class Solution {
    struct {
        int tree[10005] = {0};
        int mark[10005] = {0};
        void push_down(int p, int len){
            if (len <= 1) return;
            mark[p << 1] = max(mark[p], mark[p << 1]);
            mark[p << 1 | 1] = max(mark[p], mark[p << 1 | 1]);
            tree[p << 1] = max(tree[p << 1], mark[p << 1]);
            tree[p << 1 | 1] = max(tree[p << 1 | 1], mark[p << 1 | 1]);
            mark[p] = 0;
        }
        
        void update(int l, int r, int val, int p, int cl, int cr){
            if(cl >= l && cr <= r){
                tree[p] = max(tree[p], val), mark[p] = max(mark[p], val);
                return ;
            }
            push_down(p, cr - cl + 1);
            int mid = (cl + cr) >> 1;
            if(mid >= l)
                update(l, r, val, p << 1, cl, mid);
            if(mid < r)
                update(l, r, val, p << 1 | 1, mid + 1, cr);
            tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
        }
        int query(int l, int r, int p, int cl, int cr){
            if(cl >= l && cr <= r)
                return tree[p];
            push_down(p, cr - cl + 1);
            int mid = (cl + cr) >> 1;
            int ans = 0;
            if(mid >= l)
                ans = max(ans, query(l, r, p << 1, cl, mid));
            if(r > mid)
                ans = max(ans, query(l, r, p << 1 | 1, mid + 1, cr));
            return ans;
        }
        
    } t;
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> p;
        for(const auto &pos : positions)
            p.push_back(pos.front()), p.push_back(pos.front() + pos.back() - 1);
        
        sort(p.begin(), p.end());
        int sz = unique(p.begin(), p.end()) - p.begin();
        int cur = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < sz; ++i)
            mp[p[i]] = i;
        vector<int> res;
        for(const auto &v : positions){
            int q1 = mp[v.front()], q2 = mp[v.front() + v.back() - 1];
            int h = t.query(q1, q2, 1, 0, sz - 1) + v.back();
            cur = max(cur, h);
            res.push_back(cur);
            t.update(q1, q2, h, 1, 0, sz - 1);
        }
        return res;
        
    }
};