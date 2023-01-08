//Segment Tree
//Runtime 429 
//Memory Usage 127.9
class MajorityChecker {
public:
    constexpr static int MAXN = 2e4 + 5;
    
    struct Node {
        int majority, count;
    };
    
    int n;
    vector<Node> tree;
    vector<int> nums;
    vector<vector<int>> indices;
    
    Node merge(const Node &l, const Node &r) {
        if(l.majority == r.majority)
            return {l.majority, l.count + r.count};
        
        if(l.count < r.count) {
            return {r.majority, r.count - l.count};
        } else {
            return {l.majority, l.count - r.count};
        }
    }
    
    void build(int u, int l, int r) {
        if (l == r) 
            return void(tree[u] = {nums[l - 1], 1});
        
        int mid = l + (r - l) / 2;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        
        return void(tree[u] = merge(tree[u << 1], tree[u << 1 | 1]));
    }
    
    Node qry(int u, int l, int r, int L, int R) {
        if(L <= l && r <= R)
            return tree[u];
        int mid = l + (r - l) / 2;
        Node ln = {0, 0}, rn = {0, 0};
        if(mid >= L)
            ln = qry(u << 1, l, mid, L, R);
        if(mid + 1 <= R)
            rn = qry(u << 1 | 1, mid + 1, r, L, R);
        return merge(ln, rn);
    }
    
    MajorityChecker(vector<int>& arr) {
        nums = arr;
        n = arr.size();
        tree.resize(n << 2);
        indices.resize(MAXN);
        for(int i = 0; i < n; ++i)
            indices[arr[i]].push_back(i);
        build(1, 1, n);
    }
    
    int query(int left, int right, int threshold) {
        int num = qry(1, 1, n, left + 1, right + 1).majority;
        if(num == 0)
            return -1;
        auto &u = indices[num];
        
        auto l = lower_bound(u.begin(), u.end(), left);
        auto r = upper_bound(u.begin(), u.end(), right);
        
        return (r - l >= threshold) ? num : -1;   
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */