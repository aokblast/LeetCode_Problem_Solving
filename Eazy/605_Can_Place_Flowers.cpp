//
//Runtime 12
//Memory Usage 20.3
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(flowerbed[0] == 0 && ( 1 == flowerbed.size() || flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            if(--n <= 0)return true; 
        }
        for(int i = 1; i < flowerbed.size(); ++i){
            if(flowerbed[i - 1] == 0 && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) && flowerbed[i] == 0){flowerbed[i] = 1; if(--n <= 0)return true;}
        }
        return n <= 0;
    }
};