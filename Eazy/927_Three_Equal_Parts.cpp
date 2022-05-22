//
//Runtime 52
//Memory Usage 40.5


class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return {-1, -1};
        vector<int> ones;
        for(int i = 0; i < n; ++)
            if(arr[i] == 1)
                ones.push_back(i);
        if(ones.size() % 3)
            return {-1, -1};
        if(ones.size() == 0)
            return {0, 2};
        int a = ones.size() / 3, b = ones.size() / 3 * 2;
        int base1 = ones[a], base2 = ones[b];
        
        for(int i = 0; i < ones.size() / 3; ++i, ++a, ++b){
            int t = ones[i] - ones[0];
            if((t) != (ones[a] - base1) || (t) != (ones[b] - base2))
                return {-1, -1};
        }
        int lim = n - ones[b - 1] - 1;

        if((base2 - ones[a - 1] - 1) < lim || (base1 - ones[ones.size() / 3 - 1] - 1) < lim)
            return {-1, -1};
            
        return {ones[ones.size() / 3 - 1] + lim, ones[ones.size() / 3 * 2 - 1] + 1 + lim};
        
        
        
    }
};