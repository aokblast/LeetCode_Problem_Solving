//Greedy
//Runtime 113
//Memory Usage 63.3

const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int top = arr[0], n = arr.size();
        unordered_map<int, int> mp;


        for(int i = 1; i < n; ++i) {
            if(top > arr[i])
                ++mp[top];
            else
                ++mp[arr[i]], top = arr[i];
            if(mp[top] == k)
                return top;
        }

        return top;
    }
};