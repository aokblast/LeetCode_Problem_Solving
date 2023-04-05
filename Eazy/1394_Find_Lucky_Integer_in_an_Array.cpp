//
//Runtime 0
//Memory Usage 10.2
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnts[505] = {0};

        for(const auto num : arr)
            cnts[num]++;

        for(int i = 500; i; --i)
            if(cnts[i] == i)
                return i;
        return -1;
    }
};