//
//Runtime 276
//Memory Usage  313.7
const int MAXN = 5e5 + 5;
class RangeModule {
    struct segTree{
        int tree[MAXN];
        int mark[MAXN];
        int lc[MAXN], rc[MAXN];
        int cnt = 0;
        segTree(){
            memset(tree, 0, sizeof(tree));
            memset(mark, -1, sizeof(mark));
            memset(rc, 0, sizeof(rc));
            memset(lc, 0, sizeof(lc));
        }
        void push_down(int p){
            if(!lc[p])
                lc[p] = ++cnt;
            if(!rc[p])
                rc[p] = ++cnt;
            if(mark[p] != -1){
                mark[lc[p]] = mark[rc[p]] = mark[p];
                tree[lc[p]] = tree[rc[p]] = mark[p];
                mark[p] = -1;
            }
                
        }
        void update(int l, int r, int val, int p, int cl, int cr){
            if(l <= cl && r >= cr){
                tree[p] = mark[p] = val;
                return;
            }
            push_down(p);
            int mid = (cl + cr) >> 1;
            if(mid >= l)
                update(l, r, val, lc[p], cl, mid);
            if(r >= mid + 1)
                update(l, r, val ,rc[p], mid + 1, cr);
            tree[p] = tree[lc[p]] && tree[rc[p]];
        }
        bool query(int l, int r, int p, int cl, int cr){
            if(l <= cl && r >= cr)
                return tree[p];
            push_down(p);
            int mid = (cl + cr) >> 1;
            bool ans = 1;
            if(mid >= l)
                ans = ans && query(l, r, lc[p], cl, mid);
            if(r >= mid + 1)
                ans = ans && query(l, r, rc[p], mid + 1, cr);
            return ans;

        }
    }t;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        t.update(left, right - 1, true, 0, 1, 1e9);
    }
    
    bool queryRange(int left, int right) {
        return t.query(left, right - 1, 0, 1, 1e9);
    }
    
    void removeRange(int left, int right) {
        t.update(left, right - 1, false, 0, 1, 1e9);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */