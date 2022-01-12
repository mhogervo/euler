#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?

// Notes. The number cannot end in {0,2,4,6,8}. Nor can the sum be a multiple of 3. Thus the only candidates have n=1, n=4 and n=7.

int testPrimalityBruteForce(const int n) {
    assert(n>=2);
    int max = floor(sqrt(n));
    for(int d=2; d<=max; d++)
        if(n % d == 0)
            return false;
    return true;
}

int prodVector(const vector <int> v) {
    // Product of all elements of a vector of integers.
    vector <int> w = v;
    int out = 1;
    while (!w.empty() && out != 0)
        {
            out *= w.back();
            w.pop_back();
        }
    return out;
}

int vecToInt(const vector <int> v) {
    // Take a vector an spit out the corresponding integer.
    int out = 0;
    vector <int> w = v;
    int pow = 1;
    while (!w.empty())
        {
            out += pow*w.back();
            w.pop_back();
            pow *= 10;
            
        }
    return out;
}
        
void printVector(const vector <int> v) {
    for(int i : v)
        std::cout << i << " "; 
    std::cout << std::endl;
}

int main ()
{
    int biggestPrimeSoFar = 0;
    
    vector <int> v = {1,2,3,4};
    do {
        // printVector(v);
        int n = vecToInt(v);
        // std::cout << n << std::endl;
        if(n > biggestPrimeSoFar && testPrimalityBruteForce(n))
            biggestPrimeSoFar = n;
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << "Biggest prime with n=4: " << biggestPrimeSoFar << ".\n";

    v = {1,2,3,4,5,6,7};
    do {
        int n = vecToInt(v);
        if(n > biggestPrimeSoFar && testPrimalityBruteForce(n))
            biggestPrimeSoFar = n;
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << "Biggest prime with n=7: " << biggestPrimeSoFar << ".\n";
    
    
    //for(int q=2; q<=15; q++)
    //    std::cout << q << " " << testPrimalityBruteForce(q) << std::endl;
    
    return 0;
}
