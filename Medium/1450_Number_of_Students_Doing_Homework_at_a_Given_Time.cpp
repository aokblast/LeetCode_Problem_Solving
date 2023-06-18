//
//Runtime 0
//Memory 10.9
class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        int n = s.size(), res = 0;

        for (int i = 0; i < n; ++i)
            res += s[i] <= q && e[i] >= q;
        
        return res;
    }
};