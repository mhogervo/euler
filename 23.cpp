#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> divisors(const int n) {
    // spit out the proper divisors of n
    assert(n>=1);
    
    vector <int> out = {};
    
    if(n>=2) {
        // out.push_back(n);
        
        for(int d=2; d<=floor(sqrt(n)); d++) {
            if( n%d == 0 ) {
                out.push_back(d);
                if(n != pow(d,2))
                    out.push_back(n/d);
            }
        }
    }
    sort(out.begin(),out.end());
    return out;
}


// int testPrimalityBruteForce(const int n) {
//     assert(n>=2);
//     int max = floor(sqrt(n));
//     for(int d=2; d<=max; d++)
//         if(n % d == 0)
//             return false;
//     return true;
// }

int sumVector(const vector <int> v) {
    // Sum of all elements of a vector of integers.
    vector <int> w = v;
    int out = 0;
    while (!w.empty())
        {
            out += w.back();
            w.pop_back();
        }
    return out;
}


bool testAbundance(const int n) {
    assert(n>=1);
    if(sumVector(divisors(n)) > n)
        return true;
    else
        return false;
}

// int prodVector(const vector <int> v) {
//     // Product of all elements of a vector of integers.
//     vector <int> w = v;
//     int out = 1;
//     while (!w.empty() && out != 0)
//         {
//             out *= w.back();
//             w.pop_back();
//         }
//     return out;
// }

// int vecToInt(const vector <int> v) {
//     // Take a vector an spit out the corresponding integer.
//     int out = 0;
//     vector <int> w = v;
//     int pow = 1;
//     while (!w.empty())
//         {
//             out += pow*w.back();
//             w.pop_back();
//             pow *= 10;
            
//         }
//     return out;
// }
        
void printVector(const vector <int> v) {
    for(int i : v)
        std::cout << i << " "; 
    std::cout << std::endl;
}

int main ()
{

    vector <int> abundantList = {12};
    int maxInt = 28123;
    // make a list of all abundant numbers that can appear 
    for(int n = 13; n <= maxInt-12; n++) {
        if(testAbundance(n))
            abundantList.push_back(n);
    }

    
    bool isSum[maxInt];
    //  bool isAbundant[maxInt];
    for(int i=1;i<=maxInt;i++) {
        isSum[i-1] = false;
        //isAbundant[i] = false;
    }

    for(int p : abundantList) {
        for(int q : abundantList) {
            int s = p+q;
            if(q >= p && s <= maxInt)
                isSum[s-1] = true;
        }
    }

    long count = 0;
    for(int n = 1; n <= maxInt; n++)
        if(!isSum[n-1])
            count += n;
    
    std::cout << "Sum of non-abundant guys is " << count << ".\n";
    
          
    return 0;
}
