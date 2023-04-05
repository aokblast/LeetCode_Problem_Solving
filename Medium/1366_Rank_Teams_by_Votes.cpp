//
//Runtime 14
//Memory Usage 10.5

class Solution {
private:
    struct E{
        int dp[26] = {0};
        int idx{0}; 
    };
public:
    string rankTeams(vector<string>& votes) {
       int d[26][26] = {0};
       bool appear[26] = {false};

       int n = votes[0].size();

       for(const auto a : votes[0])
        appear[a - 'A'] = true;


        for(const auto &vote : votes) {
            for(int i = 0; i < n; ++i) {
                d[vote[i] - 'A'][i]++;
            }
        }

        E e[n];

        for(int i = 0, j = 0; i < 26; ++i) {
            if(appear[i]) {
                memcpy(e[j].dp, d[i], sizeof(d[0]));
                e[j].idx = i;
                ++j;
            }
        } 

        sort(e, e + n, [](const auto &a, const auto &b) {
            for(int i = 0; i < 26; ++i) {
                if(a.dp[i] < b.dp[i])
                    return false;
                else if(a.dp[i] > b.dp[i])
                    return true;
            }
            return a.idx < b.idx;
        });

        string res;

        for(const auto &e_ : e) {
            res += static_cast<char>(e_.idx + 'A');
        }

        return res;
    }
};