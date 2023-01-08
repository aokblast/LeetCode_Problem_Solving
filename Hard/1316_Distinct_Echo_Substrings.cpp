//Robin-Karp
//Runtime 189
//Memory Usage 6.9

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        constexpr static long base = 29;
        constexpr static long MOD = 1e9 + 7;
        unordered_set<long> st;
        long hash[n + 1], power[n + 1];
        hash[0] = 0;
        power[0] = 1;
        for(int i = 0; i < n; ++i) {
            hash[i + 1] = (hash[i] * base + text[i] - 26) % MOD;
            power[i + 1] = (power[i] * base) % MOD;
        }

        auto getHash = [&](int l, int r) {
            return ((hash[r] - hash[l] * power[r - l]) % MOD + MOD) % MOD;
        };

        for(int l = 1; l <= n / 2; ++l) {
            int cnt = 0;
            for(int i = 0, j = l; j < n; ++j, ++i) {
                if(text[i] == text[j])
                    ++cnt;
                else
                    cnt = 0;

                if(cnt == l) {
                    st.insert(getHash(i, i + l));
                    --cnt;
                }
            }
        }
        return st.size();
    }
};