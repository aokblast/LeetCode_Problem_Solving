//Binary search
//Runtime 254
//Memory Usage 93.6
class SnapshotArray {
public:
    int id = 0;
    vector<vector<pair<int, int>>> arr;
    SnapshotArray(int length) {
        arr.resize(length);
        for(auto &p : arr)
            p.push_back({0, 0});
    }
    
    void set(int index, int val) {
        if(arr[index].back().first == id) {
            arr[index].back().second = val;
        } else {
            arr[index].push_back({id, val});
        }
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto &u = arr[index];
        return (--lower_bound(u.begin(), u.end(), make_pair(snap_id + 1, -1)))->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */