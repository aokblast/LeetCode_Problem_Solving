//
//Runtime 31
//Memory Usage 9.5
class Solution {
private:
class BIT {
private:
    int sz;
    int tr[3 * 10000 + 1];

    static int lowerbit(int x) {
        return x & -x;
    }
public:
    BIT(int sz): sz(sz) {
        memset(tr, 0, sizeof(tr));
    }
    void add(int idx, int v) {
        while(idx <= sz)
            tr[idx] += v, idx += lowerbit(idx);
    }

    int sum(int idx) {
        int res = 0;

        while(idx)
            res += tr[idx], idx -= lowerbit(idx);
            
        return res;
    }
};
public:
    string minInteger(string num, int k) {
        int n = num.size();
        queue<int> q[10];

        for(int i = 0; i < n; ++i)
            q[num[i] - '0'].push(i + 1);

        BIT tr(n);
        string res;

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(!q[j].empty()) {
                    int t = q[j].front(); 
                    int pos = t + tr.sum(t);
                    if(pos - i <= k) {
                        k -= pos - i;
                        res += (char)(j + '0');
                        q[j].pop();
                        tr.add(1, 1);
                        tr.add(t, -1);
                        break;
                    }
                }
            }
        }   
        return res;
    }
};