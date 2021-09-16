//
//Runtime 4
//Memory Usage 9
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for(int &n : nums){
            if(n > m1) {
                m3 = m2;
                m2 = m1;
                m1 = n;
            }
            else if(n > m2 && n < m1) {m3 = m2; m2 = n;}
            else if(n > m3 && n < m2) m3 = n;
        }
        return m3 == LONG_MIN ? m1 : m3;
    }
};
