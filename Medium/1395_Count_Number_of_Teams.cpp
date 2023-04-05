//BIT
//Runtime 15
//Memory Usage 9.8

class Solution {
    struct BIT {
        int val[(int)1e5 + 5] = {0}; 

        void update(int idx, int num) {
            while(idx <= 1e5) 
                val[idx] += num, idx += idx & (-idx);
        }

        int query(int idx) {
            int res = 0;

            while(idx) 
                res += val[idx], idx -= idx & (-idx);

            return res;
        }

        int suf(int idx) {
            return query(1e5) - query(idx - 1);
        }
    };
public:
    int numTeams(vector<int>& rating) {
        BIT l, r;
        int res = 0;

        for(const auto rat : rating)
            r.update(rat, 1);
        
        for(const auto rat : rating) {
            r.update(rat, -1);
            res += l.query(rat - 1) * r.suf(rat + 1);
            res += l.suf(rat + 1) * r.query(rat - 1);
            l.update(rat, 1);
        }

        return res;
    }
};