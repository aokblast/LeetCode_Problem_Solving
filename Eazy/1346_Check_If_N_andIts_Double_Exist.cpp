//
//Runtime 8
//Memory Usage 10.3

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;

        for(const int num : arr) 
            if(st.count(num * 2) || (num % 2 == 0 && st.count(num / 2)))
                return true;
            else
                st.insert(num);

        return false;
    }
};