//greedy
//Runtime 68
//Memory Usage 42

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), l = 0, r = n - 1, res = 0;
        while(l < r){
            while(l < r && people[l] + people[r] > limit)
                --r, ++res;
            if(l < r){
                ++l, --r;
                ++res;   
            }
            if(l >= r){
                res += l == r;
                break;
            }
        }
        return res;
        
    }
};