//stack
//Runtime 8
//Memory Usage 17.6

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> res;
        int n = as.size();
        for(int i = 0; i < n; ++i){
            bool last = true;
            if(as[i] < 0){
                while(!res.empty() && res.back() > 0){
                    if(res.back() == -as[i]){
                        last = false;
                        res.pop_back();
                        break;
                    }else if(res.back() > -as[i]){
                        last = false;
                        break;
                    }else{
                        last = true;
                        res.pop_back();
                    }
                }
                if(last)
                    res.push_back(as[i]);
            }else{
                res.push_back(as[i]);
            }
            
        }
        return res;
    }
};