//dp
//Runtime 120
//Memory Usage 66.2

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a = -1, b = -1, res = 0, cur = 0, cb = 0;
        
        for(const int fruit : fruits){
            if(fruit == a || fruit == b)
                ++cur;
            else
                cur = cb + 1;
            
            if(fruit == b)
                ++cb;
            else
                a = b, b = fruit, cb = 1;
            
            res = max(res, cur);
        }
        return res;
    }
};