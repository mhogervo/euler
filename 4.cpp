#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

vector <int> intToArray(const int n)
{
    assert(n>=0);
    // take an integer and return an array of its decimals, i.e. 682 -> {6,8,2}
    int tp = n, rem;
    vector <int> outArray;
    while(true) {
        rem = tp % 10;
        outArray.insert(outArray.begin(), rem);
        //outArray.push_back(rem);
        tp = (tp-rem)/10;
        if (tp==0)
            return outArray;
    }
}

bool checkPalindrome(const int n)
{
    vector <int> decimalRep = intToArray(n);

    vector <int> flippedRep = decimalRep;
    std::reverse(flippedRep.begin(),flippedRep.end());

    return (decimalRep == flippedRep);
}

int main ()
{
    int biggestPalindrome = 0;
    int min = 100, max = 999;

    for(int m=min; m<=max; m++) {
         for(int n=min; n<=m; n++) {
             long prod = m*n;
             if(checkPalindrome(prod)&&prod>biggestPalindrome)
                 biggestPalindrome = prod;
         }
    }
    
    std::cout << "The biggest palindrome found was " << biggestPalindrome << ".\n";

    //for (int s : palindromeList)
    //    std::cout << s << ' ';
    
        
    return 0;
}
