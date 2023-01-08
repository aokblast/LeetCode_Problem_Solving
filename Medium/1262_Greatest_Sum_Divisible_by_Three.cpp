//Greedy
//Runtime 36
//Memory Usage 25.1


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res = 0, m11 = INT_MAX, m12 = INT_MAX, m21 = INT_MAX, m22 = INT_MAX;
        
        for(const int num : nums) {
            res += num;

            if(num % 3 == 1) {
                if(num <= m11) 
                    m12 = m11, m11 = num;
                else if(num < m12)
                    m12 = num;
            } else if(num % 3 == 2) {
                if(num <= m21) 
                    m22 = m21, m21 = num;
                else if(num < m22)
                    m22 = num;
            }
        }

        int ans = 0;
        if(res % 3 == 1) {
            if(m11 != INT_MAX)
                ans = max(ans, res - m11);
            if(m21 != INT_MAX && m22 != INT_MAX)
                ans = max(ans, res - m21 - m22);  
        } else if(res % 3 == 2) {
            if(m11 != INT_MAX && m12 != INT_MAX)
                ans = max(ans, res - m11 - m12);
            if(m21 != INT_MAX)
                ans = max(ans, res - m21);
        } else {
            ans = res;
        }
        return ans;
    }
};