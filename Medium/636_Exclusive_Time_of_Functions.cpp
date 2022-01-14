//
//Runtime 12
//Memory Usage 13.4
class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        vector<pair<int, int>> stk;
        int idx, time;
        for(const auto &log : logs){
            idx = time = 0;
            int i = 0;
            for(; log[i] != ':'; ++i) idx = idx * 10 + log[i] - '0';
            ++i;
            int mode = log[i] == 'e' ? 1 : -1;
            for(; log[i] != ':'; ++i);
            ++i;
            for(; i != log.size(); ++i) time = time * 10 - '0' + log[i];
            if(mode == 1){
                res[idx] += time - stk.back().first + 1;
                stk.pop_back();
                if(!stk.empty())stk.back().first = time + 1;
            }else{
                if(stk.empty()){
                    stk.push_back({time, idx});
                }else{
                    res[stk.back().second] += time - stk.back().first;
                    stk.back().first = time;
                    stk.push_back({time, idx});
                }
            }
        }
        return res;
    }
};