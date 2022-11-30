#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

int PRECISION_RECIPROCAL = 10000;

bool isPrime(long i, std::vector<long> primes) {
    bool isDivideble = false;
    for (long j : primes) {
        if (i % j == 0) {
            isDivideble = true;
        }
    }
    return !isDivideble;
}
std::vector<int> reciprocal(long prime) {
    long number = 1;
    long numbersAfterZero = 0;
    std::vector<int> anwser;
    long divider = prime;
    while (number < divider) {
        numbersAfterZero++;
        number = number * 10;
    }

    while (numbersAfterZero > 0) {
        anwser.push_back(0);
        numbersAfterZero--;
    }
    int divided = number / divider;
    anwser.push_back(divided);
    number = (number % divider) * 10;
    while (PRECISION_RECIPROCAL > anwser.size()) {
        divided = number / divider;
        anwser.push_back(divided);
        number = (number % divider) * 10;
    }
    return anwser;
}

void printReciprocal(std::vector<int> reciprocalNum) {
    for (int i : reciprocalNum) {
        std::cout << i;
    }
    std::cout << "\n";
}

int main()
{
    //setup
    std::vector<long> numbers;
    std::vector<long> primes;
    std::vector<std::vector<int>> reciprocals;

    primes.push_back(2);

    long x;
    std::cout << "[Log]Starting program\n[MESSAGE]to what number do i need to search: ";
    std::cin >> x;

    auto start = std::chrono::high_resolution_clock::now();

    for (long i = 3; i <= x; i++) {
        long  num = i;
        numbers.push_back(num);
    }

    //main code
    for (long i : numbers) {
        bool isNumberPrime = isPrime(i, primes);
        if (isNumberPrime) {
            primes.push_back(i);
            std::vector<int> reciprocalNumber = reciprocal(i);
            reciprocals.push_back(reciprocalNumber);
        }
    }

    //getting time
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    //printing output
    ///*primes
    for (long i : primes) {
        std::cout << "[OUTPUT]" << i << "\n";
    }
    //*/
    /*reciprecels
    for (std::vector<int> i : reciprocals) {
        printReciprocal(i);
    }
    */
    std::cout << "[OUTPUT] elapsed time is: " << (float)duration.count() / 1000 << "s";
    

}


