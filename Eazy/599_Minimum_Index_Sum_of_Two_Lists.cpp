//
//Runtime 64
//Memory Usage 36.8
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        int n = list1.size(), m = list2.size(), ans = INT_MAX;
        vector<string> res;
        for(int i = 0; i < n; ++i){
            m1[list1[i]] = i;
        }
        for(int j = 0; j < m; ++j){
           if(m1.find(list2[j]) != m1.end()){
               int idx = m1[list2[j]] + j;
               if(idx < ans){
                   ans = idx;
                   res.clear();
                   res.push_back(list2[j]);
               }else if(idx == ans){
                   res.push_back(list2[j]);
               }
           }
        }
        return res;
        
    }
};