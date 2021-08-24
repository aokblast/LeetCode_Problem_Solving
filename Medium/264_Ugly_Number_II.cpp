//
//Runtime 4
//Memory Usage 5.8
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n + 3];
        dp[0] = 1;
        int i = 0, j=  0, k = 0;
        for(int x =1; x < n; ++x){
            int mini=dp[i]*2;
            mini=min(mini, dp[j]*3);
            mini=min(mini, dp[k]*5);
            if(mini==dp[i]*2){
                dp[x]=mini;
                i++;
            }if(mini==dp[j]*3){
                dp[x]=mini;
                j++;
            }if(mini==dp[k]*5){
                dp[x]=mini;
                k++;
            }
        }
        return dp[n - 1];
        
    }
};

//priority_queue
//Runtime 32
//Memory Usage 11
class Solution {
public:
    int nthUglyNumber(int n) {
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
       q.push({1, 2});
        n--;
       while(n--){
           pair<long long, int> f = q.top(); q.pop();
           switch(f.second){
               case 2:
                   q.push({f.first * 2, 2});
               case 3:
                   q.push({f.first * 3, 3});
               case 5:
                   q.push({f.first * 5, 5});
                   break;
           }
       }
        return q.top().first;
    }
};
