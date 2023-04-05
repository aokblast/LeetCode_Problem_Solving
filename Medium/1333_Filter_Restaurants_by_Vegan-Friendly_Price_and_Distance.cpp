//
//Runtime 92
//Memory Usage 28.2

class Solution {
public:
    

    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;

        auto f = veganFriendly ? [](int i){return i == true;} : [](int i){return true;};

        int ids[100005];

        for(const auto &v : restaurants) { 
            if(f(v[2]) && v[3] <= maxPrice && v[4] <= maxDistance)
                res.push_back(v[0]);
            ids[v[0]] = v[1];
        }
            
        sort(res.begin(), res.end(), [&](int a, int b) {return ids[a] == ids[b] ? a > b : ids[a] > ids[b];});
        return res;
    }
};