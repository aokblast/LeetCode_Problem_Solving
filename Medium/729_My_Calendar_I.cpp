//
//Runtime 92
//Memory Usage 99.5

const int MAXN = 4e4 + 5;
class MyCalendar {
public:
    struct segTree{
        struct Node{
			bool val;

		}
		bool tree[MAXN];
        int mark[MAXN];
        int lc[MAXN], rc[MAXN];
		
        int cnt = 0;
        segTree(){
            memset(tree, 0, sizeof(tree));
            memset(lc, 0, sizeof(lc));
            memset(rc, 0, sizeof(rc));
            memset(mark, -1, sizeof(mark));
        }
        void update(int l, int r, bool val, int p, int cl, int cr){
            if(l <= cl && r >= cr){
                tree[p] = mark[p] = val;
                return;
            }
            int mid = (cl + cr) >> 1;
            push_down(p);
            if(mid >= l)
                update(l, r, val, lc[p], cl, mid);
            if(r >= mid + 1)
                update(l, r, val, rc[p], mid + 1, cr);
            tree[p] = tree[lc[p]] || tree[rc[p]];
        }
        bool query(int l, int r, int p, int cl, int cr){
            if(l <= cl && r >= cr)
                return tree[p];
            int mid = (cl + cr) >> 1;
            push_down(p);
            bool res = false;
            if(mid >= l)
                res = res || query(l, r, lc[p], cl, mid);
            if(r >= mid + 1)
                res = res || query(l, r, rc[p], mid + 1, cr);
            return res;
        }
        void push_down(int p){
            
            if(!lc[p])
                lc[p] = ++cnt;
            if(!rc[p])
                rc[p] = ++cnt;
            if(mark[p] != -1){
                tree[lc[p]] = tree[rc[p]] = mark[lc[p]] = mark[rc[p]] = mark[p];
                mark[p] = -1;
            }
            
        }
    }t;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(t.query(start, end - 1, 0, 0, 1e9)){
            return false;
        }else{
            t.update(start, end - 1, true, 0, 0, 1e9);
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */