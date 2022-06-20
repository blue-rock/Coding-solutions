class FizzBuzz {
private:
    int n;
    condition_variable cv;
    mutex m;
    int count;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lck(m);
        while (true) {
            cv.wait(lck, [this]{return (count % 3 == 0 && count % 5 != 0) || (count > n);});
            if (count > n) return;
            printFizz();
            count++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lck(m);
        while (true) {
            cv.wait(lck, [this]{return (count % 3 != 0 && count % 5 == 0) || (count > n);});
            if (count > n) return;
            printBuzz();
            count++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lck(m);
        while (true) {
            cv.wait(lck, [this]{return (count % 3 == 0 && count % 5 == 0) || (count > n);});
            if (count > n) return;
            printFizzBuzz();
            count++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lck(m);
        while (true) {
            cv.wait(lck, [this]{return (count % 3 != 0 && count % 5 != 0) || (count > n);});
            if (count > n) return;
            printNumber(count);
            count++;
            cv.notify_all();
        }
    }
};