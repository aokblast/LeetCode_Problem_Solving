//
//Runtime 8
//Memory Usage 6.2

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int lim = sqrt(num + 1);
        vector<int> res = {1, num + 1};

        for(int i = lim; i >= 1; --i)
            if((num + 1) % i == 0)
                if(abs(i - (num + 1) / i) < abs(res[0] - res[1]))
                    res = {i, (num + 1) / i};

        lim = sqrt(num + 2);

        for(int i = lim; i >= 1; --i)
            if((num + 2) % i == 0)
                if(abs(i - (num + 2) / i) < abs(res[0] - res[1]))
                    res = {i, (num + 2) / i};
        
        return res;
    }
};