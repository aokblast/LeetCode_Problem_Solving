//Greedy
//Runtime 364
//Memory Usage 70.8


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const auto &v1, const auto &v2) {return v1[0] < v2[0];});

        int res = 0, i = 0, n = events.size();

        priority_queue<int, vector<int>, greater<int>> q;

        for(int d = 1; d <= 100005; ++d) {
            while(i < n && events[i][0] == d)
                q.push(events[i][1]), ++i;
            while(q.size() && q.back() < d)
                q.pop();
            if(q.size())
                ++res, q.pop();
        }

        return res;
    }
};