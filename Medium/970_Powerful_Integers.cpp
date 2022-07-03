//
//Runtime 0
//Memory 6.9
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        if(bound == 0 || bound == 1)
            return {};
        if(x == 1 && y == 1)
            return {2};
        if(x == 1){
            int lim = bound == 1 ? -1 : log(bound - 1) / log(y);
            for(int i = 0; i <= lim; ++i)
                s.insert(1 + pow(y, i));
            return vector<int>(s.begin(), s.end());
        }
        if(y == 1){
            int lim = bound == 1 ? -1 : log(bound - 1) / log(x);
            for(int i = 0; i <= lim; ++i)
                s.insert(1 + pow(x, i));
            return vector<int>(s.begin(), s.end());
        }
        int d = log(bound) / log(x);
        for(int i = 0; i <= d; ++i){
            int p = bound - pow(x, i);
            int lim = (p == 0 ? -1 : log(p) / log(y));
            cout << lim << '\n';
            for(int j = 0; j <= lim; ++j){
                s.insert(pow(x, i) + pow(y, j));
            }
            int a = pow(x, i) + pow(y, lim + 1);
            if(a <= bound)
                s.insert(a);
        }
        return vector<int>(s.begin(), s.end());
    }
};