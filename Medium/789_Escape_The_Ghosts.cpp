//Greedy
//Runtime 0
//Memory Usage 10.3

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        const int d = abs(target[0]) + abs(target[1]);
        const int a = target[0], b = target[1];
        for(const auto &ghost : ghosts){
            if(abs(ghost[0] - a) + abs(ghost[1] - b) <= d)
                return false;
        }
        return true;
    }
};