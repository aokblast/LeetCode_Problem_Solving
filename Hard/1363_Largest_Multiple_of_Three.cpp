//Greedy
//Runtime 16
//Memory Usage 19.8

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string res;

        int cnts[10] = {0}, sum = 0;

        int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};

        for(const auto digit : digits)
            cnts[digit]++, sum += digit;

        while(sum % 3) {
            for(const auto idx : sum % 3 == 1 ? m1 : m2) {
                if(cnts[idx]) {
                    sum -= idx, cnts[idx]--;
                    break;
                }
            }
        }

        if(sum == 0 && cnts[0] != 0)
            return "0";

        for(int i = 9; i >= 0; --i)
            res += string(cnts[i], i + '0');

        return res;
    }
};