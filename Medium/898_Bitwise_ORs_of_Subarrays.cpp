//dp
//Runtime 663
//Memory 97.8
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        
        int n = arr.size();
        
        for(int i = 0; i < n; ++i){
            res.insert(arr[i]);
            for(int j = i - 1; j >= 0; --j){
                if((arr[j] | arr[i]) == arr[j])
                    break;
                
                arr[j] |= arr[i];
                res.insert(arr[j]);


            }
        }
        return res.size();
        
    }
};