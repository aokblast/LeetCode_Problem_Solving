//
//Runtime 0
//Memory Usage 10.2

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int bits[10005];

        for(const int num : arr)
            bits[num] = bitset<16>(num).count();

        sort(arr.begin(), arr.end(), [&](int a, int b) {return bits[a] == bits[b] ? a < b : bits[a] < bits[b];});

        return arr;
    }
};