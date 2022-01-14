//Greedy
//Runtime 212
//Memory Usage 56.2
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](const vector<int> &v1, const vector<int> &v2){return v1[1] != v2[1] ? v1[1] < v2[1] : v1[0] < v2[0];});
        int cur = 0;
        priority_queue<int> q;
        for(const auto &course : courses){
            int time = course[0];
            cur += time;
            q.push(time);
            while(cur > course[1]){
                cur -= q.top(), q.pop();
            }
        }
        return q.size();
    }
    
};