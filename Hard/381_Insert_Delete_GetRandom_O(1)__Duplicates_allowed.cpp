//Unordered_Set
//Runtime 220 
//Memory Usage 107.9
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        loc[val].insert(nums.size());
        nums.push_back(val);
        return loc[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(loc[val].empty()) return false;
        int idx = *loc[val].begin();
        loc[val].erase(idx);
        if(idx != nums.size() - 1){
            int tmp = nums.back();
            nums[idx] = tmp;
            loc[tmp].erase(nums.size() - 1);
            loc[tmp].insert(idx);
        }
        nums.pop_back();
        return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    vector<int> nums;
    unordered_map<int, unordered_set<int>> loc;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
