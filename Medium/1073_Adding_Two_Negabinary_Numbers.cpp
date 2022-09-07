//
//Runtime 7
//Memory Usage 19.5
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int m = arr1.size(), n = arr2.size();
        int l = max(m, n) + 2;
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int carry = 0, r = 0;
        
        for(int i = 0; i < l; ++i) {
            int a = i < m ? arr1[i] : 0;
            int b = i < n ? arr2[i] : 0;
            r = (a + b + carry) % -2;
            carry = (a + b + carry) / -2;
            if(r < 0)
                r += 2, carry += 1;
            res.push_back(r);
        }
        
        while(res.back() == 0 && res.size() != 1)
            res.pop_back();
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};