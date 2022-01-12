#include <iostream>
#include <cmath>
using namespace std;

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

// Logic: the difference is 2 \sum_{1<= i < j <= n} i j. The partial sum 2 \sum_{1 <= j < i} = i(i-1).
int main ()
{

    int count = 0, max = 100;
    for(int i=1; i<=max; i++)
        count += i*i*(i-1);
    std::cout << "The difference is " << count << std::endl;
    
    return 0;
}
