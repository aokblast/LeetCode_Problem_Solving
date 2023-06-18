//Greedy
//Runtime 76
//Memory Usage 35.6


class SmallestInfiniteSet {
public:
    set<int> st;
    int cur = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!st.size())
            return cur++;
        else {
            int top = *(st.begin()); st.erase(st.begin());
            return top;
        }
    }
    
    void addBack(int num) {
        if(num < cur)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */