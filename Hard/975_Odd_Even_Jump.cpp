//dp
//Runtime 144
//Memory Usage 35.6
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        map<int, bool> odd, even;
        
        int res = 1, n = arr.size();
        odd[(arr[n - 1] << 14) | 1] = even[(arr[n - 1] << 14) | (n - 1)] = true;
        for(int i = n - 2; i >= 0; --i){
            int val = arr[i];
            auto ev = odd.lower_bound((val + 1) << 14);
            auto od = even.lower_bound(val << 14);
            bool o = (od != even.end()) && (od->second), e = (ev != odd.begin()) && ((--ev)->second);
            even[(val << 14) | i] = e;
            res += odd[(val << 14) | (n - i)] = o;
        }
        return res;
    }
};

