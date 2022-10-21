//
//Runtime 7
//Memory Usage 9.9
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        deque<int> q;
        
        for(int i = 0; i < n; ++i) {
            if(arr[i] == 0) {
                q.push_back(0);
                q.push_back(0);
                arr[i] = q.front();
                q.pop_front();
            }else {
                q.push_back(arr[i]);
                arr[i] = q.front();
                q.pop_front();
            }
        }
        
    }
};