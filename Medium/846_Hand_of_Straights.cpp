//
//Runtime 76
//Memory Usage 28.3

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        
        for(const int h : hand)
            mp[h]++;
        while(mp.size()){
            bool res = false;
            int top = mp.begin()->first;
            for(int i = 0; i < groupSize; ++i){
                if(mp.find(top + i) == mp.end())
                    return false;
                if(--mp[top + i] == 0)
                    mp.erase(top + i);
            }
            
        }
        return true;
        
        
    }
};