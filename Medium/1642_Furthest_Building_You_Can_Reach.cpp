//Greedy
//Runtime 126
//Memory Usage 53.6

auto speed=[]() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr;}();

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        int i;
        for(i = 1; i < n; ++i){
            int cha = heights[i] - heights[i - 1];
            if(cha <= 0)
                continue;
            
            q.push(cha);
            
            
            if(q.size() > ladders)
                bricks -= q.top(), q.pop();
            
            
            if(bricks < 0)
                break;
            
            
        }
        return i - 1;
        
    }
}; 
