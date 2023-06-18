//Binary Search
//Runtime 213
//Memory Usage 57.8
class Solution {
public:
Solution() { ios::sync_with_stdio(0); }
    int maxDistance(vector<int>& position, int m) {
        const int n = position.size();
        auto check = [&](int val) {
            int cnt = 1;
            int last = position[0];

            for(int i = 1; i < n; ++i)
                if(position[i] - last >= val) {
                    ++cnt, last = position[i];
                    if(cnt == m)
                        return true;
                }
            return false;
        };

        sort(position.begin(), position.end());

        int l = 0, r = position[n - 1] - position[0], res = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(check(mid))
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return res;
    }
};