//TreeSet
//Runtime 12
//Memory Usage 238.6

class DinnerPlates {
    int cap = 0;
    set<int> avaStack;
    vector<vector<int>> stacks;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if(avaStack.empty()) 
            avaStack.insert(stacks.size()), stacks.resize(stacks.size() + 1);
        
        int top = *avaStack.begin();
        
        stacks[top].push_back(val);
        
        if(stacks[top].size() == cap)
            avaStack.erase(top);
    }
    
    int pop() {
        return popAtStack(stacks.size() - 1);
    }
    
    int popAtStack(int index) {
        if(index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1;
        
        int res = stacks[index].back();
        stacks[index].pop_back();
        avaStack.insert(index);
        
        while(!stacks.empty() && stacks.back().empty())
            stacks.pop_back(), avaStack.erase(*avaStack.rbegin());
        
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */