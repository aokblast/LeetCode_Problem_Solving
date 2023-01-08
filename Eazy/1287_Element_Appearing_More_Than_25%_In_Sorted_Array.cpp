//
//Runtime 20
//Memory Usage 12.8

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size() / 4 + 1;

        int mp[100005] = {0};

        for(const int num : arr)
            if(++mp[num] >= sz)
                return num;


        return -1;
    }
};