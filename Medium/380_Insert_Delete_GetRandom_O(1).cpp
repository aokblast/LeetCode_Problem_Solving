//
//Runtime 200
//Memory Usage 97.1
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(loc.find(val) != loc.end()) return false;
        nums.push_back(val);
        loc[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(loc.find(val) == loc.end()) return false;
        int end = nums.back();
        loc[end] = loc[val];
        nums[loc[end]] = end;
        loc.erase(val);
        
        nums.pop_back();
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        return nums[rand() % nums.size()];
    }
    vector<int> nums;
    unordered_map<int, int> loc;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
