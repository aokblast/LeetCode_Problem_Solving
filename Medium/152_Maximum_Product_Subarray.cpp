//Greedy
//Runtime 4
//Memory Usage 11.6

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        if(arr.size()==1){
            
            return arr[0];
        }
        
        int maxi=arr[0];
        int mini=arr[0];
        int product=arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] < 0){
                swap(maxi,mini);
            }
            
            maxi=max(arr[i],arr[i]*maxi);
            
            mini=min(arr[i],arr[i]*mini);
            
            if(maxi > product){
                product=maxi;
            }
            
        }
        return product;
    }
};
