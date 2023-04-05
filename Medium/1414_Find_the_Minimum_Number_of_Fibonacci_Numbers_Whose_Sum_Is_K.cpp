//
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> cur;

        cur.push_back(0);
        cur.push_back(1);

        while(cur.back() < k) {
            cur.push_back(cur.back() + cur[cur.size() - 2]);
        }

        int res = 0;

        for(int i = cur.size() - 1; i >= 0. && k; --i){
            if(cur[i] <= k)
                k -= cur[i], ++res;
        }

        return res;
    }
};