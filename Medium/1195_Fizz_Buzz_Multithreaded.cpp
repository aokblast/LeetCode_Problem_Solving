//
//Runtime 4
//Memory Usage 6.6

class FizzBuzz {
private:
    int n;
    int cur;
    condition_variable cv;
    mutex mx;

public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        do_work([&](int i){printFizz();}, [&]{return (cur % 3 == 0 && cur % 5 != 0);});
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        do_work([&](int i){printBuzz();}, [&]{return (cur % 5 == 0 && cur % 3 != 0);});
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        do_work([&](int i){printFizzBuzz();}, [&]{return (cur % 5 == 0 && cur % 3 == 0);});
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        do_work(printNumber, [&]{return (cur % 5 != 0 && cur % 3 != 0);});
    }
    
private:
    void do_work(function<void(int)> func, function<bool()> predi) {
        while(cur <= n) {
            std::unique_lock<std::mutex> lock(mx);
            cv.wait(lock,[&]{return predi() || cur > n;});
            if(cur > n)
                break;
            func(cur);
            ++cur;
            cv.notify_all();
        }
    }
      
};