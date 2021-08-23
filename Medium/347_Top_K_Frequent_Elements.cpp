//priority_queue + unordered_map
//Runtime 12
//Memory Usage 13.7

class dat{
    public:
        int num;
        int val;// time
        dat(int x, int y) {num = x, val = y;}
};

bool operator>(const dat &x, const dat &y) {return x.val > y.val;}
bool operator<(const dat &x, const dat &y) {return x.val < y.val;}



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<dat> que;
        unordered_map<int, int>ma;
        vector<int> vec;
        for(int i : nums){
            ++ma[i];
        }
        for(auto &i : ma ){
            que.push(dat(i.first, i.second));
        }
        while(k--){
            vec.push_back(que.top().num);
            que.pop();
        }
        return vec;
    }
};


