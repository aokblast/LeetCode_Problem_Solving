//trie
//Runtime 120
//Memory Usage 40.9
class Solution {
    struct {
        int node[400000][2] = { {0} };
        int tot = 0;
        void insert(int n) {
            int u = 0;
            for (int i = 31; i >= 0; --i) {
                bool idx = n & (1 << i);
                if (!node[u][idx]) node[u][idx] = ++tot;
                u = node[u][idx];
            }
        }
        int query(int n) {
            int u = 0;
            int ans = 0;
            for (int i = 31; i >= 0; --i) {
                bool idx = n & (1 << i);
                if (!node[u][!idx]) {
                    if (node[u][idx])u = node[u][idx];
                    else return 0;
                }
                else {
                    u = node[u][!idx];
                    ans |= (1 << i);
                }
            }
            return ans;

        }
    }trie;

public:
    int findMaximumXOR(vector<int>& nums) {
        for (int& n : nums) trie.insert(n);
        int ans = 0;
        for (int& n : nums) ans = max(ans, trie.query(n));
        return ans;
    }
};