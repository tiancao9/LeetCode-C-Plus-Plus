Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.

// Sol: semaphore. Start with the number thread.
#include<semaphore.h>
class FizzBuzz {
private:
    int n;
    sem_t fizz_, buzz_, fizz_buzz_, num_;

public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&fizz_, 0, 0);
        sem_init(&buzz_, 0, 0);
        sem_init(&fizz_buzz_, 0, 0);
        sem_init(&num_, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 != 0) {
                sem_wait(&fizz_);
                printFizz();
                sem_post(&num_);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 != 0) {
                sem_wait(&buzz_);
                printBuzz();
                sem_post(&num_);
            }
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 15; i <= n; i+=15) {
            sem_wait(&fizz_buzz_);
            printFizzBuzz();
            sem_post(&num_);
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&num_);
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
                sem_post(&num_);
            } else if (i % 3 == 0 && i % 5 != 0) {
                sem_post(&fizz_);
            } else if (i % 5 == 0 && i % 3 != 0) {
                sem_post(&buzz_);
            } else {
                sem_post(&fizz_buzz_);
            }            
        }
        
    }
};
