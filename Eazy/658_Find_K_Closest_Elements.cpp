//
//Runtime 32
//Memory Usage 32.6
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        queue<int> q;
        int n = arr.size();
        for(const int num : arr){
            if(q.size() < k)
                q.push(num);
            else if(abs(num - x) < abs(q.front() - x))
                q.pop(), q.push(num);
        }
        vector<int> res;
        while(k--)
            res.push_back(q.front()), q.pop();
        
        return res;
        
    }
};