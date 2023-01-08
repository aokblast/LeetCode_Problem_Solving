//
//Runtime 4
//Memory Usage 8.8
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int dest) {
        int n = distance.size();
        
        
        for(int i = 1; i < n; ++i)
            distance[i] += distance[i - 1];
        
        if(start > dest)
            swap(start, dest);
    
        int shun = (dest == 0 ? 0 : distance[dest - 1]) - (start == 0 ? 0 : distance[start - 1]);
        
        return min(distance[n - 1] - shun, shun);
    }
};