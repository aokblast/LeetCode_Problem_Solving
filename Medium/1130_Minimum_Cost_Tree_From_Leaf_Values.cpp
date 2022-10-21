//Greedy
//Runtime 3
//Memory Usage 8.6

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        list<int> list;
        
        list.push_back(1e6);
        for(const int num : arr)
            list.push_back(num);
        
        list.push_back(1e6);
        
        while(list.size() > 3) {
            auto iter = min_element(list.begin(), list.end());
            auto p = iter;
            
            auto n = iter;
            p--;
            n++;
            int cur = *iter, prev = *(p), next = *(n);
            
            if(prev < next) {
                int val = cur * prev;
                res += val;
                list.insert(iter, prev);
                list.erase(p);
            } else {
                int val = cur * next;
                res += val;
                list.insert(iter, next);
                list.erase(n);
            }
            
            list.erase(iter);
            
        }
        return res;
    }
};