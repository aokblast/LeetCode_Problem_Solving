//
//Runtime 654
//Memory Usage 129.5

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i = 0; i < n; ++i)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end(), [](const auto &t1, const auto &t2) {return t1[0] == t2[0] ? t1[1] < t2[1] : t1[0] < t2[0];});

        using pii = pair<int, int>;
        vector<int> res;
        long cur = tasks[0][0];
        priority_queue<pii, vector<pii>, greater<pii>> q;

        
        int j = 0;
        while(j < n) {
            cur = tasks[j][0];
            q.push({tasks[j][1], tasks[j][2]});
            ++j;
            while(q.size()) {
                auto [t,idx] = q.top(); q.pop();
                cur += t;
                res.push_back(idx);

                while(j < n && tasks[j][0] <= cur)
                    q.push({tasks[j][1], tasks[j][2]}), ++j;
            }
        }


        return res;
    }
};