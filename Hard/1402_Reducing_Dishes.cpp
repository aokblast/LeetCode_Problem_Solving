//Greedy
//Runtime 4
//Memory Usage 8

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int cur = 0, sum = 0;

        for(const int num : satisfaction) {
            cur += num;

            if(cur > 0)
                sum += cur;
            else
                break;
        }

        return sum;
    }
};