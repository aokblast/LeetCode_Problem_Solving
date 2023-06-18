//
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    int kthFactor(int n, int k) {
        int lim = sqrt(n);

        vector<int> factors;

        for(int i = 1; i <= lim; ++i) 
            if(n % i == 0)
                factors.push_back(i), factors.push_back(n / i);

        if(lim * lim == n)
            factors.pop_back();
        
        if(factors.size() < k)
            return -1;

        nth_element(factors.begin(), factors.begin() + k - 1, factors.end(), less<int>());

        return factors[k - 1];
    }
};