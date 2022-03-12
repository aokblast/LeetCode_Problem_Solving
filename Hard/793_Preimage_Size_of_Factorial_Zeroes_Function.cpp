//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int preimageSizeFZF(int k) {
        if(k < 5)
            return 5;
        int cnt = 1;
        while(cnt * 5 + 1 <= k)
            cnt = cnt * 5 + 1;
        if(k / cnt == 5)
            return 0;
        return preimageSizeFZF(k % cnt);
    }
};