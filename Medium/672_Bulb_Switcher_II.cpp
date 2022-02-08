//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int flipLights(int n, int p) {
        if(n == 1)
            return vector<int>({1, 2})[min(p, 1)];
        else if(n == 2)
            return vector<int>({1, 3, 4})[min(p, 2)];
        else 
            return vector<int>({1, 4, 7, 8})[min(p, 3)];
            
    }
};