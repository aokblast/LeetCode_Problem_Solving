//
//Runtime 64
//Memory 89.6
const int MAXN = 3.8e4 + 5;
class MyCalendarThree {
    struct {
        int mark[MAXN] = {0};
        int tree[MAXN] = {0};
        int lc[MAXN] = {0}, rc[MAXN] = {0};
        int cnt = 0;
        void push_down(int p){
            if(!lc[p])
                lc[p] = ++cnt;
            if(!rc[p])
                rc[p] = ++cnt;
            if(mark[p]){
                int val = mark[p];
                tree[lc[p]] += val;
                tree[rc[p]] += val;
                mark[rc[p]] += val;
                mark[lc[p]] += val;
                mark[p] = 0;
            }
            
        }
        void update(int l, int r, int val, int p, int cl, int cr){
            if(cl >= l && r >= cr){
                tree[p] += val, mark[p] += val;
                return;
            }
            push_down(p);
            int mid = (cl + cr) >> 1;
            if(mid >= l)
                update(l, r, val, lc[p], cl, mid);
            if(r >= mid + 1)
                update(l, r, val, rc[p], mid + 1, cr);
            tree[p] = max(tree[lc[p]], tree[rc[p]]);
        }
        int query(int l, int r, int p, int cl, int cr){
            if(cl >= l && r >= cr)
                return tree[p];
            push_down(p);
            int mid = (cl + cr) >> 1;
            int res = 0;
            if(mid >= l)
                res = max(res, query(l, r, lc[p], cl, mid));
            if(r >= mid + 1)
                res = max(res, query(l, r, rc[p], mid + 1, cr));
            return res;
        }
    }t;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        t.update(start, end - 1, 1, 0, 0, 1e9);
        return t.query(0, 1e9, 0, 0, 1e9);
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */