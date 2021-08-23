//Greedy
//Runtime 0
//Memory Usage 9.8


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length  = gas.size();
        int cum = 0, ga, cos;
        int i, dc = 0, result = 0;
        for(i = 0; i < length; ++i){
            ga = gas[i], cos = cost[i];
            cum += (ga -cos);
            dc += (ga -cos);
            if(dc < 0) result = i + 1, dc = 0; 
        }
        return cum >= 0 ? result : -1;

    }
};
