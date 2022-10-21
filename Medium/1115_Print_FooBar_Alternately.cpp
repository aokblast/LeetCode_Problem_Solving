// 
//Runtime 8
//Memory Usage 6.6

class FooBar {
private:
    int n;
    atomic<bool> alt;

public:
    FooBar(int n) {
        this->n = n;
        alt = false;
    }

    void foo(function<void()> printFoo) {
        
        
        for (int i = 0; i < n; i++) {
            while(alt)
                this_thread::yield();
            
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            alt = !alt;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(!alt)
                this_thread::yield();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            alt = !alt;
        }
    }
};

