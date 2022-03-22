//
//Runtime 86
//Memory Usage 34.7

static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ps[121] = {0};
        int frq[121] = {0};
        for(const int age : ages)
            ++frq[age];
        for(int i = 1; i <= 120; ++i)
            ps[i] = ps[i - 1] + frq[i];
        
        int res = 0;
        for(int i = 15; i <= 120; ++i){
            int l = 0.5 * i + 7;
            res += (ps[i] - ps[l] - 1) * frq[i];
            
        }
        return res;
    }
};