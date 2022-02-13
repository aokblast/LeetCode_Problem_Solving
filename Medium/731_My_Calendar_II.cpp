//Segment Tree
//Runtime 96
//Memory Usage 134.8

const int MAXN = 5.9e4 + 5;
class MyCalendarTwo {
    struct segTree{
        int tree[MAXN];
        int mark[MAXN];
        int lc[MAXN], rc[MAXN];
        int cnt = 0;
        segTree(){
            memset(tree, 0, sizeof(tree));
            memset(lc, 0, sizeof(lc));
            memset(rc, 0, sizeof(rc));
            memset(mark, 0, sizeof(mark));
        }
        void update(int l, int r, bool val, int p, int cl, int cr){
            if(l <= cl && r >= cr){
                tree[p] += val, mark[p] += val;
                return;
            }
            int mid = (cl + cr) >> 1;
            push_down(p);
            if(mid >= l)
                update(l, r, val, lc[p], cl, mid);
            if(r >= mid + 1)
                update(l, r, val, rc[p], mid + 1, cr);
            tree[p] = max(tree[lc[p]], tree[rc[p]]);
        }
        int query(int l, int r, int p, int cl, int cr){
            if(l <= cl && r >= cr)
                return tree[p];
            int mid = (cl + cr) >> 1;
            push_down(p);
            int res = 0;
            if(mid >= l)
                res = max(res, query(l, r, lc[p], cl, mid));
            if(r >= mid + 1)
                res = max(res, query(l, r, rc[p], mid + 1, cr));
            return res;
        }
        void push_down(int p){
            
            if(!lc[p])
                lc[p] = ++cnt;
            if(!rc[p])
                rc[p] = ++cnt;
            if(mark[p]){
                tree[lc[p]] += mark[p];
                tree[rc[p]] += mark[p];
                mark[lc[p]] += mark[p];
                mark[rc[p]] += mark[p];
                mark[p] = 0;
            }
            
        }
    }t;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if(t.query(start, end - 1, 0, 0, 1e9) == 2){
            return false;
        }else{
            t.update(start, end - 1, 1, 0, 0, 1e9);
            return true;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */