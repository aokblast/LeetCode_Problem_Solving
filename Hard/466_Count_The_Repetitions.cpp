//
//Runtime 27
//Memory Usage 14.9
class Solution {
public:
    int idx[1000000 + 5] = {0};
    int cnt[1000000 + 5] = {0};
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int n = s1.size(), m = s2.size();
        int index = 0, count = 0;
        for(int i = 1; i <= n1; ++i){
            for(int j = 0; j < n; ++j){
                index += (s1[j] == s2[index]);
                if(index == m){
                    index = 0;
                    ++count;
                }
            }
            cnt[i] = count, idx[i] = index;
            for(int start = 0; start < i; ++start){
                if(idx[start] == index){
                    int interval = (i - start);
                    int rep = (n1 - start) / interval;
                    return ((cnt[i] - cnt[start]) *rep + cnt[start + (n1 - start) % interval]) / n2;
                    
                    
                }
            }
            

        }
        return cnt[n1] / n2;
        
    }
};
